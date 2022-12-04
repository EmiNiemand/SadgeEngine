//
// Created by szymo on 27/10/2022.
//

#include "../lib/SadgeTile.h"

Sadge::SadgeTile::SadgeTile(SDL_Texture *texture, SDL_Rect shapeAndPosition, TileType type) : SadgeActor(texture, shapeAndPosition), type(type) {}

Sadge::SadgeTile::~SadgeTile() {}

Sadge::TileType Sadge::SadgeTile::getType() const {
    return type;
}


