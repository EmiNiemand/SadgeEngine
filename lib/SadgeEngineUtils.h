//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEENGINEUTILS_H
#define SADGEENGINE_SADGEENGINEUTILS_H

#include <SDL_image.h>
#include <string>

namespace Sadge{
    class SadgeEngineUtils {
    public:
        static SDL_Texture* CreateTexture(std::string path, SDL_Renderer* renderer);
        static SDL_Rect CreateRect(int width, int height, int x, int y);
    };
}


#endif //SADGEENGINE_SADGEENGINEUTILS_H
