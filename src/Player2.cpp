//
// Created by szymo on 13/10/2022.
//

#include "../lib/Player2.h"

Sadge::Player2::Player2(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn) : SadgePawn(texture,
                                                                                      shapeAndPosition, bGravityOn) {}


void Sadge::Player2::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player2::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    int XPos;
    int YPos;
    SDL_GetMouseState( &XPos, &YPos );
    Lerp(x, y, XPos, YPos, 0.1);
    setNewPosition(x - this->getShapeAndPosition().w / 2, y - this->getShapeAndPosition().h / 2);
}

void Sadge::Player2::Lerp(int &X, int &Y, int XDest, int YDest, double LerpValue) {
    X = X + (XDest - X) * LerpValue;
    Y = Y + (YDest - Y) * LerpValue;
}
