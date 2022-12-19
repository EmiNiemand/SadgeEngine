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
    double JUMP;
};

namespace Sadge{
    class Player1 : public SadgePawn {
    private:
        PlayerMoveState PlayerMovingState{};
        int JumpCount = 2;
        int MaxJumpCount = 2;
        double SecondJumpDelay = 0.3;
        double SecondJumpTimer = 0;
        bool bIsJumping = false;
        double MoveSpeed;

        float H = 1.5;
        float Xh = 5.5;
        float Vx = 10;
        float V0;
        float FallVelocity = 2.5;
    public:
        Player1(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn, double MoveSpeed);

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList,
                    std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns,
                    std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList,
                  std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns,
                  std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) override;

        void CheckCollision(std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns) override;
        void CheckCollisionActors(std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) override;

        void HandleEvent(std::vector<SDL_Event> &EventList);
    };
}


#endif //SADGEENGINE_PLAYER1_H
