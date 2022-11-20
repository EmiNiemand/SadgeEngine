//
// Created by szymo on 13/10/2022.
//

#include "../lib/Player2.h"

#include <iostream>

Sadge::Player2::Player2(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn, SadgeCamera* cam, float& scale) : SadgePawn(texture,
                                                                                      shapeAndPosition, bGravityOn), Cam(cam), Scale(scale) {}


void Sadge::Player2::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player2::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    int XPos;
    int YPos;
    SDL_GetMouseState(&XPos, &YPos);
    XPos = (XPos / Scale + Cam->getCameraPos().x);
    YPos = (YPos / Scale + Cam->getCameraPos().y);

    Lerp(x, y, XPos, YPos, 0.1);
    setNewPosition(Vector2<double>(x - this->getShapeAndPosition().w / 2, y - this->getShapeAndPosition().h / 2));
}

void Sadge::Player2::Lerp(int &X, int &Y, int XDest, int YDest, double LerpValue) {
    X = X + (XDest - X) * LerpValue;
    Y = Y + (YDest - Y) * LerpValue;
}
