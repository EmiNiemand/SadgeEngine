//
// Created by szymo on 02/11/2022.
//

#ifndef SADGEENGINE_CAMERAFORBOTHPLAYERS_H
#define SADGEENGINE_CAMERAFORBOTHPLAYERS_H

#include "SDL.h"
#include "SadgePawn.h"
#include "SadgeCamera.h"
#include <iostream>
#include <memory>

namespace Sadge {
    class CameraForBothPlayers : public SadgeCamera {
    public:
        CameraForBothPlayers(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize);

        ~CameraForBothPlayers() override;

        void Update(std::shared_ptr<SadgePawn> PawnToFocus, std::shared_ptr<SadgePawn> PawnToFocus2, float Scale);
    };
}


#endif //SADGEENGINE_CAMERAFORBOTHPLAYERS_H
