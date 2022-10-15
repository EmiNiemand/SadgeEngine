//
// Created by szymo on 13/10/2022.
//

#include "../lib/Player2.h"

Sadge::Player2::Player2(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) : SadgePawn(texture,
                                                                                      shapeAndPosition, bGravityOn) {}


void Sadge::Player2::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player2::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    HandleEvent(EventList);
    setNewPosition(x - this->getShapeAndScreenPosition()->w / 2, y - this->getShapeAndScreenPosition()->h / 2);
}

void Sadge::Player2::HandleEvent(std::vector<SDL_Event> &EventList) {
for (SDL_Event e : EventList) {
    if (e.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState( &x, &y );
        }
    }
}