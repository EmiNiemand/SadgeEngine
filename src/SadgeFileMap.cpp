//
// Created by szymo on 15/10/2022.
//

#include "../lib/SadgeFileMap.h"
#include "../lib/SadgeEngineUtils.h"
#include "../lib/SadgeActor.h"
#include <iostream>
#include <fstream>

Sadge::SadgeFileMap::SadgeFileMap(std::string Path) {
    FileContent = ReadFile(Path);
}

std::vector<std::string> Sadge::SadgeFileMap::ReadFile(std::string& Path) {
    std::vector<std::string> Content;
    std::string Line;
    std::ifstream File(Path);

    if (!File.is_open()) {
        std::cerr << "Could not open the file";
        return Content;
    }

    while (getline(File, Line)) {
        Content.push_back(Line);
    }
    File.close();

    return Content;
}

void Sadge::SadgeFileMap::CreateMap(SDL_Renderer* Renderer, std::string UpWallPath, std::string SideWallPath, std::string FloorPath) {
    int i = 0;
    int j = 0;
    for(std::string Line : FileContent) {
        i = 0;
        for(char Character : Line){
            if(Character == '|') {
                SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(SideWallPath, Renderer);
                SDL_Rect Tile = SadgeEngineUtils::CreateRect(30, 30, 0 + 30 * i, 0 + 30 * j);
                MapTiles.push_back(std::make_pair(TileTexture, Tile));
            }
            else if(Character == '.' && ((j == 0 || FileContent.at(j - 1)[i] != '.') ||
            (j + 1 == FileContent.size() || (j != 0 && j < FileContent.size() && FileContent.at(j + 1)[i] != '.')))) {
                printf("%zu, %i\n", FileContent.size(), j);
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
        j++;
    }
}

void Sadge::SadgeFileMap::RenderMap(SDL_Renderer *Renderer) {
    for(std::pair<SDL_Texture*, SDL_Rect> Tile : MapTiles){
        SDL_RenderCopy(Renderer, Tile.first, nullptr, &Tile.second);
    }
}
