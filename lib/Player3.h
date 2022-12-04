//
// Created by szymo on 02/12/2022.
//

#ifndef SADGEENGINE_PLAYER3_H
#define SADGEENGINE_PLAYER3_H

#include "Player1.h"

namespace Sadge{
    class Player3 : public SadgePawn{
    private:
        PlayerMoveState PlayerMovingState{};
        double MoveSpeed;
    public:
        Player3(SDL_Texture *texture, const SDL_Rect &shapeAndPosition, bool bGravityOn, double moveSpeed);

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList) override;

        void CheckCollision(std::shared_ptr<Sadge::SadgePawn> CollidingPawn) override;
        void CheckCollisionActors(std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) override;

        void HandleEvent(std::vector<SDL_Event> &EventList);
    };
}



#endif //SADGEENGINE_PLAYER3_H
