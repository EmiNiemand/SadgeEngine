//
// Created by szymo on 19/10/2022.
//

#ifndef SADGEENGINE_SADGEFILEMAP_H
#define SADGEENGINE_SADGEFILEMAP_H

#include "SDL.h"
#include "SadgeActor.h"
#include "SadgeEngineUtils.h"
#include <string>
#include <vector>

namespace Sadge{
    class SadgeFileMap {
    private:
        std::string FileContent;
        std::vector<std::pair<SDL_Texture*, SDL_Rect>> MapTiles;
        std::pair<uint64_t, uint64_t> MapSize;
    public:
        SadgeFileMap(std::string Path);

        void CreateMap(SDL_Renderer* Renderer, std::string UpWallPath, std::string SideWallPath, std::string FloorPath);
        void RenderMap(SDL_Renderer* Renderer, SDL_Rect Camera);

        const std::pair<uint64_t, uint64_t> &getMapSize() const;

    private:
        std::string ReadFile(std::string& Path);
    };
}



#endif //SADGEENGINE_SADGEFILEMAP_H
