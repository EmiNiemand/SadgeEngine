//
// Created by szymo on 07/10/2022.
//

#include "../lib/SadgePawn.h"

Sadge::SadgePawn::SadgePawn(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn) : SadgeActor(texture,
                                                                    shapeAndPosition), bGravityOn(bGravityOn) {
    RealPosition.first = shapeAndPosition.x;
    RealPosition.second = shapeAndPosition.y;
}

Sadge::SadgePawn::~SadgePawn() {}

void Sadge::SadgePawn::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    Move(DeltaTime, EventList);
    if(bGravityOn) {
        Shift(0 * DeltaTime, 98.1 * DeltaTime);
    }
}

void Sadge::SadgePawn::Shift(double x, double y) {
    auto Position = getRealPosition();
    setNewPosition(Position.first + x, Position.second + y);
}

const std::pair<double, double> &Sadge::SadgePawn::getRealPosition() const {
    return RealPosition;
}

void Sadge::SadgePawn::setNewPosition(double x, double y) {
    RealPosition.first = x;
    RealPosition.second = y;
    this->setPosition((int)(RealPosition.first), (int)(RealPosition.second));
}
