//
// Created by szymo on 12/10/2022.
//

#ifndef SADGEENGINE_PLAYER1_H
#define SADGEENGINE_PLAYER1_H

#include "SDL.h"
#include "SadgePawn.h"

namespace Sadge{
    class Player1 : public SadgePawn {
    public:
        Player1(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn);

        void Update(double DeltaTime, std::vector<SDL_Event> EventList) override;

        void Move(double DeltaTime, std::vector<SDL_Event> EventList) override;
    };
}


#endif //SADGEENGINE_PLAYER1_H
