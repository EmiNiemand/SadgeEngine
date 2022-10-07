//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEACTOR_H
#define SADGEENGINE_SADGEACTOR_H

#include <SDL_image.h>
#include <utility>
#include <cstdint>

namespace Sadge{
    class SadgeActor {
    private:
        SDL_Texture* Texture;
        SDL_Rect* ShapeAndPosition;
    public:
        SadgeActor(SDL_Texture *texture, SDL_Rect *shapeAndPosition);
        virtual ~SadgeActor() = 0;

        SDL_Texture *getTexture() const;
        SDL_Rect *getShapeAndPosition() const;

        void setNewPosition(int x, int y);

    };

}

#endif //SADGEENGINE_SADGEACTOR_H
