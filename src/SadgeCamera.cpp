//
// Created by szymo on 02/11/2022.
//

#include "../lib/SadgeCamera.h"

Sadge::SadgeCamera::SadgeCamera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize) : CameraPos(
        cameraPos), MapSize(mapSize) {}

Sadge::SadgeCamera::~SadgeCamera() {

}

const SDL_Rect &Sadge::SadgeCamera::getCameraPos() const {
    return CameraPos;
}

const std::pair<uint64_t, uint64_t> &Sadge::SadgeCamera::getMapSize() const {
    return MapSize;
}

void Sadge::SadgeCamera::setPosition(int x, int y) {
    CameraPos.x = x;
    CameraPos.y = y;
}

