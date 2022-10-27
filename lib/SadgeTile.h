//
// Created by szymo on 27/10/2022.
//

#ifndef SADGEENGINE_SADGETILE_H
#define SADGEENGINE_SADGETILE_H

#include "SadgeActor.h"

namespace Sadge{
    class SadgeTile : public SadgeActor {
    public:
        SadgeTile(SDL_Texture *texture, SDL_Rect shapeAndPosition);
        ~SadgeTile() override;
    };
}



#endif //SADGEENGINE_SADGETILE_H
