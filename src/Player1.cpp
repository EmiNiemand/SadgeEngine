//
// Created by szymo on 12/10/2022.
//

#include "../lib/Player1.h"

#include <iostream>

Sadge::Player1::Player1(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn) : SadgePawn(texture,
                                                                                       shapeAndPosition, bGravityOn) {}

void Sadge::Player1::Update(double DeltaTime, std::vector<SDL_Event> EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player1::Move(double DeltaTime, std::vector<SDL_Event> EventList) {
    for (SDL_Event e : EventList) {
        if (e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_d: Shift(500 * DeltaTime, 0 * DeltaTime);break;
                case SDLK_a: Shift(-500 * DeltaTime, 0 * DeltaTime); break;
                case SDLK_w: Shift(0 * DeltaTime, 500 * DeltaTime); break;
                case SDLK_s: Shift(0 * DeltaTime, -500 * DeltaTime); break;
            }
        }
    }
}
