//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgeActor.h"


Sadge::SadgeActor::SadgeActor(SDL_Texture *texture, SDL_Rect *shapeAndPosition) : Texture(texture),
                                                                                  ShapeAndScreenPosition(shapeAndPosition) {
    RealPosition.first = ShapeAndScreenPosition->x;
    RealPosition.second = ShapeAndScreenPosition->y;
}

Sadge::SadgeActor::~SadgeActor() {

}


SDL_Texture *Sadge::SadgeActor::getTexture() const {
    return Texture;
}

SDL_Rect *Sadge::SadgeActor::getShapeAndScreenPosition() const {
    return ShapeAndScreenPosition;
}

const std::pair<double, double> &Sadge::SadgeActor::getRealPosition() const {
    return RealPosition;
}

void Sadge::SadgeActor::setNewPosition(double x, double y) {
    RealPosition.first = x;
    RealPosition.second = y;
    ShapeAndScreenPosition->x = (int)(RealPosition.first);
    ShapeAndScreenPosition->y = (int)(RealPosition.second);
}


