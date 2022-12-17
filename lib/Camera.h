//
// Created by szymo on 26/10/2022.
//

#ifndef SADGEENGINE_CAMERA_H
#define SADGEENGINE_CAMERA_H

#include "SDL.h"
#include "SadgePawn.h"
#include "SadgeCamera.h"
#include <iostream>
#include <memory>

namespace Sadge{
    class Camera : public SadgeCamera{
    public:
        Camera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize);
        ~Camera() override;

        void Update(std::shared_ptr<SadgePawn> PawnToFocus);
    private:
        void Lerp(int &X, int XDest, double LerpValue);
    };
}

#endif //SADGEENGINE_CAMERA_H
