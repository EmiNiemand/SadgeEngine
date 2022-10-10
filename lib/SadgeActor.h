//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEACTOR_H
#define SADGEENGINE_SADGEACTOR_H

#include <SDL_image.h>
#include <utility>

namespace Sadge{
    class SadgeActor {
    private:
        SDL_Texture* Texture;
        SDL_Rect* ShapeAndScreenPosition;
        std::pair<double, double> RealPosition;
    public:
        SadgeActor(SDL_Texture *texture, SDL_Rect *shapeAndPosition);
        virtual ~SadgeActor() = 0;

        SDL_Texture *getTexture() const;
        SDL_Rect *getShapeAndScreenPosition() const;
        const std::pair<double, double> &getRealPosition() const;
        void setNewPosition(double x, double y);
    };

}

#endif //SADGEENGINE_SADGEACTOR_H
