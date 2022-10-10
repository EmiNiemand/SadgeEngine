//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePetrFat.h"

Sadge::SadgePetrFat::SadgePetrFat(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) :
SadgePawn(texture, shapeAndPosition, bGravityOn) {}

void Sadge::SadgePetrFat::Move(double DeltaTime) {
    auto playerPosition = getShapeAndScreenPosition();
    if(playerPosition->x == 0){
        Direction = 1;
    }
    else if(playerPosition->x == 1200 - getShapeAndScreenPosition()->w){
        Direction = -1;
    }
    Shift(Direction * 50, 0, DeltaTime);
}