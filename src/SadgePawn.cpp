//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePawn.h"

Sadge::SadgePawn::SadgePawn(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) : SadgeActor(texture,
                                                                    shapeAndPosition), bGravityOn(bGravityOn) {}

Sadge::SadgePawn::~SadgePawn() {}

void Sadge::SadgePawn::Update(double DeltaTime) {
    Move(DeltaTime);
    if(bGravityOn) {
        Shift(0, 98.1, DeltaTime);
    }
}

void Sadge::SadgePawn::Shift(double x, double y, double DeltaTime) {
    auto Position = getRealPosition();
    setNewPosition(Position.first + x * DeltaTime, Position.second + y * DeltaTime);
}

