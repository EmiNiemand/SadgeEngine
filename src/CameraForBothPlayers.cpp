//
// Created by szymo on 02/11/2022.
//

#include "../lib/CameraForBothPlayers.h"

Sadge::CameraForBothPlayers::CameraForBothPlayers(const SDL_Rect &cameraPos, const std::pair<uint64_t,
        uint64_t> &mapSize) : SadgeCamera(cameraPos, mapSize) {}

Sadge::CameraForBothPlayers::~CameraForBothPlayers() {

}

void Sadge::CameraForBothPlayers::Update(std::shared_ptr<SadgePawn> PawnToFocus, std::shared_ptr<SadgePawn> PawnToFocus2, float Scale) {
    SDL_Rect Pos;
    Pos.x = (PawnToFocus->getShapeAndPosition().x + PawnToFocus2->getShapeAndPosition().x) / 2;
    Pos.y = (PawnToFocus->getShapeAndPosition().y + PawnToFocus2->getShapeAndPosition().y) / 2;
    SDL_Rect CameraPos = getCameraPos();
    std::pair<uint64_t, uint64_t> MapSize = getMapSize();

    setPosition(Pos.x - CameraPos.w / 2 / Scale,Pos.y - CameraPos.h / 2 / Scale);
}

