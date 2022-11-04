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
    std::pair<uint64_t, uint64_t> MapSize = getMapSize();
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

