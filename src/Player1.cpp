//
// Created by szymo on 12/10/2022.
//

#include "../lib/Player1.h"

Sadge::Player1::Player1(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn, double moveSpeed) : SadgePawn(texture,
                                                            shapeAndPosition, bGravityOn), MoveSpeed(moveSpeed) {}

void Sadge::Player1::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player1::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    HandleEvent(EventList);
    Shift(MoveSpeed * (PlayerMovingState.RIGHT - PlayerMovingState.LEFT), MoveSpeed * (PlayerMovingState.DOWN - PlayerMovingState.UP));
}

void Sadge::Player1::HandleEvent(std::vector<SDL_Event> &EventList) {
    for (SDL_Event e : EventList) {
        if (e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_d: PlayerMovingState.RIGHT = 1;break;
                case SDLK_a: PlayerMovingState.LEFT = 1; break;
                case SDLK_w: PlayerMovingState.UP = 1; break;
                case SDLK_s: PlayerMovingState.DOWN = 1; break;
            }
        }
        else if (e.type == SDL_KEYUP) {
            switch(e.key.keysym.sym) {
                case SDLK_d: PlayerMovingState.RIGHT = 0;break;
                case SDLK_a: PlayerMovingState.LEFT = 0; break;
                case SDLK_w: PlayerMovingState.UP = 0; break;
                case SDLK_s: PlayerMovingState.DOWN = 0; break;
            }
        }
    }
}
