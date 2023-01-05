//
// Created by szymo on 19/10/2022.
//

#ifndef SADGEENGINE_SADGEFILEMAP_H
#define SADGEENGINE_SADGEFILEMAP_H

#include "SDL.h"
#include "SadgeTile.h"
#include "SadgeEngineUtils.h"
#include "../lib/SadgeCamera.h"
#include <string>
#include <vector>
#include <memory>

namespace Sadge{
    class SadgeFileMap {
    private:
        std::string FileContent;
        std::vector<std::shared_ptr<Sadge::SadgeActor>> MapTiles;
        std::pair<uint64_t, uint64_t> MapSize;
    public:
        SadgeFileMap(std::string Path);

        void CreateMap(SDL_Renderer* Renderer, std::string UpWallPath, std::string SideWallPath, std::string FloorPath, int TileSize);
        void RenderMap(double Scale, SadgeCamera* Cam, SDL_Renderer* Renderer, Vector2<double> Speed = {1, 1});
        const std::vector<std::shared_ptr<Sadge::SadgeActor>> &getMapTiles() const;
        const std::pair<uint64_t, uint64_t> &getMapSize() const;

    private:
        std::string ReadFile(std::string& Path);
    };
}



#endif //SADGEENGINE_SADGEFILEMAP_H
