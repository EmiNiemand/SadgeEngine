//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGECLOUD_H
#define SADGEENGINE_SADGECLOUD_H

#include "SadgeActor.h"

namespace Sadge {
    class SadgeCloud : public SadgeActor {
    public:
        SadgeCloud(SDL_Texture *texture, SDL_Rect *shapeAndPosition);
        ~SadgeCloud() override;
    };
}


#endif //SADGEENGINE_SADGECLOUD_H
