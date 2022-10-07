//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePawn.h"

Sadge::SadgePawn::SadgePawn(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) : SadgeActor(texture,
    shapeAndPosition), bGravityOn(bGravityOn) {}

Sadge::SadgePawn::~SadgePawn() {}

void Sadge::SadgePawn::Update() {
    Move();
    if(bGravityOn) {
        Shift(0, 9);
    }
}

void Sadge::SadgePawn::Shift(int x, int y) {
    SDL_Rect* Position = getShapeAndPosition();
    setNewPosition(Position->x + x, Position->y + y);
}


