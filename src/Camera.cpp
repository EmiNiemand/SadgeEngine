//
// Created by szymo on 26/10/2022.
//

#include "../lib/Camera.h"

Sadge::Camera::Camera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize) : SadgeCamera(cameraPos,
                                                                                                             mapSize) {}

Sadge::Camera::~Camera() {

}

void Sadge::Camera::Update(std::shared_ptr<SadgePawn> PawnToFocus) {
    SDL_Rect Pos = PawnToFocus->getShapeAndPosition();
    SDL_Rect CameraPos = getCameraPos();
    Lerp(CameraPos.x, Pos.x + Pos.w / 2 - CameraPos.w / 2, 0.05);
    Lerp(CameraPos.y, Pos.y + Pos.h / 2 - CameraPos.h / 2, 0.1);

    setPosition(CameraPos.x, CameraPos.y);
}

void Sadge::Camera::Lerp(int &X, int XDest, double LerpValue) {
    X = X + (XDest - X) * LerpValue;
}

