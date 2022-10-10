//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEPAWN_H
#define SADGEENGINE_SADGEPAWN_H

#include "SadgeActor.h"

namespace Sadge{
    class SadgePawn : public SadgeActor {
    private:
        bool bGravityOn;
    public:
        SadgePawn(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn);
        ~SadgePawn() override;

        virtual void Update(double DeltaTime);
        virtual void Move(double DeltaTime) = 0;
    protected:
        void Shift(double x, double y, double DeltaTime);
    };
}


#endif //SADGEENGINE_SADGEPAWN_H
