//
// Created by szymo on 12/10/2022.
//

#ifndef SADGEENGINE_PLAYER1_H
#define SADGEENGINE_PLAYER1_H

#include "SDL.h"
#include "SadgePawn.h"

struct PlayerMoveState {
    double RIGHT;
    double LEFT;
    double UP;
    double DOWN;
};

namespace Sadge{
    class Player1 : public SadgePawn {
    private:
        PlayerMoveState PlayerMovingState{};
        double MoveSpeed;
        double SmoothSide = 0;
        double SmoothUp = 0;
        double SideVelocity;
        double UpVelocity;
        int8_t PreviousStateSide = 0;
        int8_t PreviousStateUp = 0;
    public:
        Player1(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn, double MoveSpeed);

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList) override;

        void HandleEvent(std::vector<SDL_Event> &EventList);
    };
}


#endif //SADGEENGINE_PLAYER1_H
