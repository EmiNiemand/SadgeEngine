//
// Created by szymo on 12/10/2022.
//

#include "../lib/Player1.h"
#include "cmath"
#include "../lib/SadgeTile.h"

Sadge::Player1::Player1(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn, double moveSpeed) : SadgePawn(texture,
                                                            shapeAndPosition, bGravityOn), MoveSpeed(moveSpeed) {}

void Sadge::Player1::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player1::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    HandleEvent(EventList);
    Shift(Vector2<double>(MoveSpeed * (PlayerMovingState.RIGHT - PlayerMovingState.LEFT), MoveSpeed * (PlayerMovingState.DOWN - PlayerMovingState.UP)));
}

void Sadge::Player1::HandleEvent(std::vector<SDL_Event> &EventList) {
    for (SDL_Event e : EventList) {
        if (e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_d: PlayerMovingState.RIGHT = 1;break;
                case SDLK_a: PlayerMovingState.LEFT = 1; break;
                case SDLK_w: PlayerMovingState.UP = 1; break;
                case SDLK_s: PlayerMovingState.DOWN = 1; break;
            }
        }
        else if (e.type == SDL_KEYUP) {
            switch(e.key.keysym.sym) {
                case SDLK_d: PlayerMovingState.RIGHT = 0;break;
                case SDLK_a: PlayerMovingState.LEFT = 0; break;
                case SDLK_w: PlayerMovingState.UP = 0; break;
                case SDLK_s: PlayerMovingState.DOWN = 0; break;
            }
        }
    }
}

void Sadge::Player1::CheckCollision(std::shared_ptr<Sadge::SadgePawn> CollidingPawn) {
    Vector2<double> Pos = getRealPosition();
    Vector2<double> ColPos = CollidingPawn->getRealPosition();

    double Size = (double)getShapeAndPosition().w / 2;
    double Radius = (double)CollidingPawn->getShapeAndPosition().w / 2;
    double Distance = Pos.distance(ColPos);

    Vector2<double> helper = Pos - ColPos;
    double cos = (helper.x * 1 - helper.y * 0) / (std::sqrt(std::pow(helper.x, 2) + std::pow(helper.y, 2)));
    double Length;
    if(cos < 0.5 && cos >= 0){
        cos = 1 - cos;
    }
    else if(cos > -0.5 && cos <= 0){
        cos = 1 + cos;
    }

    Length = std::abs(Size / cos);

    if(Distance <= Length + Radius && ((PlayerMovingState.RIGHT - PlayerMovingState.LEFT) != 0 ||
                                       (PlayerMovingState.DOWN - PlayerMovingState.UP) != 0)){
        Vector2<double> v = (Pos - ColPos) / Distance * (Length + Radius - Distance);
        setNewPosition(Pos + v);
    }
}

void Sadge::Player1::CheckCollisionActors(std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) {
    for(std::shared_ptr<Sadge::SadgeActor> Actor : CollidingActors){
        auto Tile = std::static_pointer_cast<SadgeTile>(Actor);

        if(Tile->getType() == Wall) {
            Vector2<double> Pos = getRealPosition();
            Vector2<double> ColPos(Tile->getShapeAndPosition().x, Tile->getShapeAndPosition().y);

            double Size = (double)getShapeAndPosition().w / 2;
            Pos.x += Size;
            Pos.y += Size;
            double TileSize = (double)Tile->getShapeAndPosition().w / 2;
            ColPos.x += TileSize;
            ColPos.y += TileSize;

            double DistanceX = std::abs(Pos.x - ColPos.x);
            double DistanceY = std::abs(Pos.y - ColPos.y);

            /*printf("Player1: %f, %f\n", getRealPosition().x, getRealPosition().y);*/

            if(DistanceX <= Size + TileSize && DistanceY <= Size + TileSize){
                if(DistanceX > DistanceY && (PlayerMovingState.RIGHT - PlayerMovingState.LEFT) != 0){
                    Shift(Vector2<double>(-(PlayerMovingState.RIGHT - PlayerMovingState.LEFT) * (TileSize + Size - DistanceX), 0));
                }
                else if(DistanceY > DistanceX && (PlayerMovingState.DOWN - PlayerMovingState.UP) != 0){
                    Shift(Vector2<double>(0, -(PlayerMovingState.DOWN - PlayerMovingState.UP) * (TileSize + Size - DistanceY)));
                }
            }
        }
    }
}
