//
// Created by szymo on 27/10/2022.
//

#ifndef SADGEENGINE_SADGETILE_H
#define SADGEENGINE_SADGETILE_H

#include "SadgeActor.h"

namespace Sadge{
    enum TileType{
        Wall,
        Ground
    };
    class SadgeTile : public SadgeActor {
        TileType type;
    public:
        SadgeTile(SDL_Texture *texture, SDL_Rect shapeAndPosition, TileType type);
        ~SadgeTile() override;

        TileType getType() const;
    };
}



#endif //SADGEENGINE_SADGETILE_H
