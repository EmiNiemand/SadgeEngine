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
    SDL_Rect Pos = PawnToFocus->getShapeAndPosition();
    if(Pos.x + 100 <= CameraPos.w / 2) {
        setPosition(0, CameraPos.y);
    }
    else if(Pos.x - 100 >= MapSize.first - CameraPos.w / 2) {
        setPosition(MapSize.first - CameraPos.w, CameraPos.y);
    }
    else{
        if(abs((Pos.x - CameraPos.w / 2) - CameraPos.x) > 100) {
            if((Pos.x - CameraPos.w / 2) - CameraPos.x > 100) {
                setPosition(Pos.x - CameraPos.w / 2 - 100,CameraPos.y);
            }
            else if((Pos.x - CameraPos.w / 2) - CameraPos.x < 100) {
                setPosition(Pos.x - CameraPos.w / 2 + 100,CameraPos.y);
            }
        }
    }
    if(Pos.y <= CameraPos.h / 2) {
        setPosition(CameraPos.x, 0);
    }
    else if(Pos.y >= MapSize.second - CameraPos.h / 2) {
        setPosition(CameraPos.x, MapSize.second - CameraPos.h);
    }
    else {
        setPosition(CameraPos.x,Pos.y - CameraPos.h / 2);
    }
}