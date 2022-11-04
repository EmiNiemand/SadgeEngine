//
// Created by szymo on 02/11/2022.
//

#ifndef SADGEENGINE_SADGECAMERA_H
#define SADGEENGINE_SADGECAMERA_H

#include "SDL.h"
#include "SadgePawn.h"
#include <iostream>
#include <memory>


namespace Sadge{
    class SadgeCamera {
    private:
        SDL_Rect CameraPos;
        std::pair<uint64_t, uint64_t> MapSize;
    public:
        SadgeCamera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize);
        virtual ~SadgeCamera() = 0;

        const SDL_Rect &getCameraPos() const;
        const std::pair<uint64_t, uint64_t> &getMapSize() const;
        void setPosition(int x, int y);
    };
}



#endif //SADGEENGINE_SADGECAMERA_H
