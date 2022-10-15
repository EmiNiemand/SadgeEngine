//
// Created by szymo on 12/10/2022.
//

#include "../lib/Player1.h"

#include <iostream>

Sadge::Player1::Player1(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn, double moveSpeed) : SadgePawn(texture,
                                                            shapeAndPosition, bGravityOn), MoveSpeed(moveSpeed) {}

void Sadge::Player1::Update(double DeltaTime, std::vector<SDL_Event> &EventList) {
    SadgePawn::Update(DeltaTime, EventList);
}

void Sadge::Player1::Move(double DeltaTime, std::vector<SDL_Event> &EventList) {
    HandleEvent(EventList);
    if((PlayerMovingState.RIGHT == 1 && PlayerMovingState.LEFT == 0) || (PlayerMovingState.LEFT == 1 && PlayerMovingState.RIGHT == 0)) {
        if(PreviousStateSide == 1 && PlayerMovingState.LEFT == 1)
        {
            SmoothSide = 0;
        }
        else if(PreviousStateSide == -1 && PlayerMovingState.RIGHT == 1)
        {
            SmoothSide = 0;
        }
        SmoothSide = SDL_clamp(SmoothSide + DeltaTime, 0, 1);
        SideVelocity = (1 - SmoothSide) * SideVelocity + (PlayerMovingState.RIGHT - PlayerMovingState.LEFT) * MoveSpeed * SmoothSide;
        PreviousStateSide = (int8_t)(PlayerMovingState.RIGHT - PlayerMovingState.LEFT);
    }
    else if((PlayerMovingState.RIGHT == 1 && PlayerMovingState.LEFT == 1) || (PlayerMovingState.RIGHT == 0 && PlayerMovingState.LEFT == 0)) {
        int8_t Side = 1;
        if(SideVelocity < 0) {
            Side = -1;
        }
        SmoothSide = SDL_clamp(SmoothSide - DeltaTime, 0, 1);
        SideVelocity = Side * SmoothSide * MoveSpeed;
    }
    if((PlayerMovingState.UP == 1 && PlayerMovingState.DOWN == 0) || (PlayerMovingState.DOWN == 1 && PlayerMovingState.UP == 0)) {
        if(PreviousStateUp == 1 && PlayerMovingState.UP == 1)
        {
            SmoothUp = 0;
        }
        else if(PreviousStateUp == -1 && PlayerMovingState.DOWN == 1)
        {
            SmoothUp = 0;
        }
        SmoothUp = SDL_clamp(SmoothUp + DeltaTime, 0, 1);
        UpVelocity = (1 - SmoothUp) * UpVelocity + (PlayerMovingState.DOWN - PlayerMovingState.UP) * MoveSpeed * SmoothUp;
        PreviousStateUp = (int8_t)(PlayerMovingState.DOWN - PlayerMovingState.UP);
    }
    else if((PlayerMovingState.UP == 1 && PlayerMovingState.DOWN == 1) || (PlayerMovingState.UP == 0 && PlayerMovingState.DOWN == 0)) {
        int8_t Side = 1;
        if(UpVelocity < 0) {
            Side = -1;
        }
        SmoothUp = SDL_clamp(SmoothUp - DeltaTime, 0, 1);
        UpVelocity = Side * SmoothUp * MoveSpeed;
    }

    Shift(SideVelocity, UpVelocity);
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
