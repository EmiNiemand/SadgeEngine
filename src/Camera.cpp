//
// Created by szymo on 26/10/2022.
//

#include "../lib/Camera.h"

Sadge::Camera::Camera(const SDL_Rect &cameraPos, const std::pair<uint64_t, uint64_t> &mapSize) : CameraPos(cameraPos),
                                                                                                 MapSize(mapSize) {}

const SDL_Rect &Sadge::Camera::getCameraPos() const {
    return CameraPos;
}

void Sadge::Camera::setPosition(int x, int y) {
    CameraPos.x = x;
    CameraPos.y = y;
}

void Sadge::Camera::Update(std::shared_ptr<SadgePawn> PawnToFocus) {
    SDL_Rect* Pos = PawnToFocus->getShapeAndScreenPosition();
    if(abs((Pos->x - CameraPos.w / 2) - CameraPos.x) > 100) {
        Lerp(CameraPos.x, Pos->x - CameraPos.w / 2, 0.02);
    }
    setPosition(CameraPos.x,(Pos->y + Pos->h / 2) - CameraPos.h / 2);

}

void Sadge::Camera::Lerp(int &X, int XDest, double LerpValue) {
    X = X + (XDest - X) * LerpValue;
}