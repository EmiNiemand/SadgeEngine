//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePawn.h"

Sadge::SadgePawn::SadgePawn(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn) :
SadgeActor(texture, shapeAndPosition), bGravityOn(bGravityOn) {
    RealPosition.x = shapeAndPosition.x;
    RealPosition.y = shapeAndPosition.y;
}

Sadge::SadgePawn::~SadgePawn() {}

void Sadge::SadgePawn::Update(double DeltaTime, std::vector<SDL_Event> &EventList,
                              std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns,
                              std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) {
    if(bGravityOn) {
        Velocity.y -= G * DeltaTime;
        if(Velocity.y <= G) {
            Velocity.y = G;
        }
    }
    Move(DeltaTime, EventList, CollidingPawns, CollidingActors);
}

void Sadge::SadgePawn::Shift(Vector2<double> vector2) {
    auto Position = getRealPosition();
    setNewPosition(Vector2<double>(Position.x + vector2.x, Position.y + vector2.y));
}

const Vector2<double> &Sadge::SadgePawn::getRealPosition() const {
    return RealPosition;
}

void Sadge::SadgePawn::setNewPosition(Vector2<double> position) {
    RealPosition.x = position.x;
    RealPosition.y = position.y;
    this->setPosition((int)(RealPosition.x), (int)(RealPosition.y));
}
