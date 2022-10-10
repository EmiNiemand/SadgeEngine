//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEPETRFAT_H
#define SADGEENGINE_SADGEPETRFAT_H

#include "SadgePawn.h"

namespace Sadge {
    class SadgePetrFat : public SadgePawn{
    private:
        int8_t Direction = 1;
    public:
        SadgePetrFat(SDL_Texture *texture, SDL_Rect *shapeAndPosition, bool bGravityOn = true);

        void Move(double DeltaTime) override;
    };
}



#endif //SADGEENGINE_SADGEPETRFAT_H
