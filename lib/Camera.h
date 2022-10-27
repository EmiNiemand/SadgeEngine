//
// Created by szymo on 26/10/2022.
//

#ifndef SADGEENGINE_CAMERA_H
#define SADGEENGINE_CAMERA_H

#include "SDL.h"
#include "SadgePawn.h"
#include <iostream>
#include <memory>

namespace Sadge{
    class Camera {
    private:
        SDL_Rect CameraPos;
        std::pair<uint64_t, uint64_t> MapSize;
    public:
        Camera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize);

        const SDL_Rect &getCameraPos() const;
        void setPosition(int x, int y);
        void Update(std::shared_ptr<SadgePawn> PawnToFocus);
    };
}

#endif //SADGEENGINE_CAMERA_H
