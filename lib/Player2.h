//
// Created by szymo on 13/10/2022.
//

#ifndef SADGEENGINE_PLAYER2_H
#define SADGEENGINE_PLAYER2_H

#include "SadgePawn.h"

namespace Sadge{
    class Player2 : public SadgePawn {
    private:
        int x, y;
    public:
        Player2(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn);

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList) override;

        void HandleEvent(std::vector<SDL_Event> &EventList);
    };
}


#endif //SADGEENGINE_PLAYER2_H
