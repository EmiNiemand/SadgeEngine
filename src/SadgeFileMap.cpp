//
// Created by szymo on 19/10/2022.
//

#include "../lib/SadgeFileMap.h"
#include "../lib/SadgeEngineUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>


Sadge::SadgeFileMap::SadgeFileMap(std::string Path) {
    FileContent = ReadFile(Path);
}

std::string Sadge::SadgeFileMap::ReadFile(std::string& Path) {
    std::ifstream File(Path);
    std::stringstream Str;
    Str << File.rdbuf();
    std::string Content = Str.str();
    return Content;
}

void Sadge::SadgeFileMap::CreateMap(SDL_Renderer* Renderer, std::string UpWallPath, std::string SideWallPath, std::string FloorPath) {
    int i = 0;
    int j = 0;
    for(char Character : FileContent) {
        if(Character == '\n')
        {
            i = 0;
            j++;
            continue;
        }
        else if(Character == '|') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(SideWallPath, Renderer);
            SDL_Rect Tile = SadgeEngineUtils::CreateRect(30, 30, 0 + 30 * i, 0 + 30 * j);
            MapTiles.push_back(std::make_pair(TileTexture, Tile));
        }
        else if(Character == '-') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(UpWallPath, Renderer);
            SDL_Rect Tile = SadgeEngineUtils::CreateRect(30, 30, 0 + 30 * i, 0 + 30 * j);
            MapTiles.push_back(std::make_pair(TileTexture, Tile));
        }
        else if(Character == '.') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(FloorPath, Renderer);
            SDL_Rect Tile = SadgeEngineUtils::CreateRect(30, 30, 0 + 30 * i, 0 + 30 * j);
            MapTiles.push_back(std::make_pair(TileTexture, Tile));
        }
        i++;
    }
    MapSize = std::make_pair(i * 30, j * 30);
}

void Sadge::SadgeFileMap::RenderMap(SDL_Renderer *Renderer, SDL_Rect Camera) {
    for(std::pair<SDL_Texture*, SDL_Rect> Tile : MapTiles){
        SDL_Rect Pos = SadgeEngineUtils::CreateRect(Tile.second.w, Tile.second.h, Tile.second.x - Camera.x,
                                                    Tile.second.y - Camera.y);
        SDL_RenderCopy(Renderer, Tile.first, nullptr, &Pos);
    }
}

const std::pair<uint64_t, uint64_t> &Sadge::SadgeFileMap::getMapSize() const {
    return MapSize;
}
