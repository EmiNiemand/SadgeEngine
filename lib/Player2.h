//
// Created by szymo on 13/10/2022.
//

#ifndef SADGEENGINE_PLAYER2_H
#define SADGEENGINE_PLAYER2_H

#include "SadgePawn.h"
#include "SadgeCamera.h"

namespace Sadge{
    class Player2 : public SadgePawn {
    private:
        int x, y;
        SadgeCamera* Cam;
        float& Scale;
    public:
        Player2(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn, SadgeCamera* cam, float& scale);

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList) override;

        void CheckCollision(std::shared_ptr<Sadge::SadgePawn> CollidingPawn) override;
        void CheckCollisionActors(std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingPawns) override;
    private:
        void Lerp(int &X, int &Y, int XDest, int YDest, double LerpValue);
    };
}


#endif //SADGEENGINE_PLAYER2_H
