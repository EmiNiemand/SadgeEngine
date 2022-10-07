//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePetrFat.h"

Sadge::SadgePetrFat::SadgePetrFat(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) : SadgePawn(
        texture, shapeAndPosition, bGravityOn) {}


void Sadge::SadgePetrFat::Move() {
    SDL_Rect* ShapeAndPosition = getShapeAndPosition();
    if(ShapeAndPosition->x == 0){
        Direction = 1;
    }
    else if(ShapeAndPosition->x == 1200 - ShapeAndPosition->w){
        Direction = -1;
    }
    Shift(Direction * 10, 0);
}

