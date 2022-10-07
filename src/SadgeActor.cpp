//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgeActor.h"


Sadge::SadgeActor::SadgeActor(SDL_Texture *texture, SDL_Rect *shapeAndPosition) : Texture(texture),
                                                                                  ShapeAndPosition(shapeAndPosition) {}

Sadge::SadgeActor::~SadgeActor() {

}


SDL_Texture *Sadge::SadgeActor::getTexture() const {
    return Texture;
}

SDL_Rect *Sadge::SadgeActor::getShapeAndPosition() const {
    return ShapeAndPosition;
}

void Sadge::SadgeActor::setNewPosition(int x, int y) {
    ShapeAndPosition->x = x;
    ShapeAndPosition->y = y;
}
