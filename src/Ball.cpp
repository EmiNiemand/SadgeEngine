/*
//
// Created by szymo on 16/11/2022.
//

#include "../lib/Ball.h"
#include <cmath>

Sadge::Ball::Ball(SDL_Texture *texture, const SDL_Rect &shapeAndPosition, bool bGravityOn, double speed,
                  const Vector2<double> &direction) : SadgePawn(texture, shapeAndPosition, bGravityOn),
                                                              Speed(speed), Direction(direction) {}

Sadge::Ball::~Ball() {

}

void Sadge::Ball::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    EventHandler(EventList);
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Ball::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    Shift(Direction * Speed);
}

void Sadge::Ball::CheckCollision(std::shared_ptr<Sadge::SadgePawn> CollidingPawn, std::pair<uint16_t, uint16_t> WindowResolution) {
    Vector2<double> Pos = getRealPosition();
    Vector2<double> ColPos = CollidingPawn->getRealPosition();

    double Radius = (double)getShapeAndPosition().w / 2;
    double Radius2 = (double)CollidingPawn->getShapeAndPosition().w / 2;
    double BallsDistance = Pos.distance(ColPos);

    if(Pos.x - Radius < 0) {
        setNewPosition(Vector2<double>(Radius, Pos.y));
        Direction.x = -Direction.x;
    }
    else if(Pos.x + Radius > (double)WindowResolution.first) {
        setNewPosition(Vector2<double>((double)WindowResolution.first - Radius, Pos.y));
        Direction.x = -Direction.x;
    }
    if(Pos.y - Radius < 0) {
        setNewPosition(Vector2<double>(Pos.x, Radius));
        Direction.y = -Direction.y;
    }
    else if(Pos.y + Radius > (double)WindowResolution.second) {
        setNewPosition(Vector2<double>(Pos.x, (double)WindowResolution.second - Radius));
        Direction.y = -Direction.y;
    }
    if(BallsDistance <= Radius * 2) {
        if(SeparationEnabled) {
            Vector2<double> v = (Pos - ColPos) / BallsDistance * (Radius + Radius2 - BallsDistance);
            setNewPosition(Pos + v);
        }
        if(CollisionEnabled) {
            Vector2<double> normal = Pos - ColPos;
            double value =
                    Vector2<double>::dotProduct(Direction, normal) / (Direction.absolute() * normal.absolute());
            if (value > 1) value = 1;
            if (value < -1) value = -1;
            double angle = std::acos(value);
            if (Pos.y < ColPos.y) {
                Vector2<double> newDirection(Direction.rotated(angle).x, -Direction.rotated(angle).y);
                Direction = newDirection;
            } else {
                Vector2<double> newDirection(Direction.rotated(angle).x, Direction.rotated(angle).y);
                Direction = newDirection;
            }

            Vector2<double> normal2 = ColPos - Pos;
            auto ball2 = std::static_pointer_cast<Ball>(CollidingPawn);
            value = Vector2<double>::dotProduct(ball2->getDirection(), normal2) /
                    (ball2->getDirection().absolute(), normal2.absolute());
            if (value > 1) value = 1;
            if (value < -1) value = -1;
            double angle2 = std::acos(value);
            if (Pos.y < ColPos.y) {
                Vector2<double> newDirection2(ball2->getDirection().rotated(angle2).x,
                                              -ball2->getDirection().rotated(angle2).y);
                ball2->setDirection(newDirection2);
            } else {
                Vector2<double> newDirection2(ball2->getDirection().rotated(angle2).x,
                                              ball2->getDirection().rotated(angle2).y);
                ball2->setDirection(newDirection2);
            }
        }
    }
}

void Sadge::Ball::setDirection(const Vector2<double> &direction) {
    Direction = direction;
}

const Vector2<double> &Sadge::Ball::getDirection() const {
    return Direction;
}

void Sadge::Ball::EventHandler(std::vector<SDL_Event> &EventList) {
    for (SDL_Event e : EventList) {
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_e) {
                CollisionEnabled = !CollisionEnabled;
            }
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_q) {
                SeparationEnabled = !SeparationEnabled;
            }
        }
    }
}


*/
