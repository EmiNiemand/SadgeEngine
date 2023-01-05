//
// Created by szymo on 19/10/2022.
//

#include "../lib/SadgeFileMap.h"
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

void Sadge::SadgeFileMap::RenderMap(double Scale, SadgeCamera* Cam, SDL_Renderer* Renderer, Vector2<double> Speed) {
    for(std::shared_ptr<SadgeActor> Actor : MapTiles) {
        auto Position = Actor->getShapeAndPosition();
        SDL_Rect Pos;
        Pos = SadgeEngineUtils::CreateRect(Position.w * Scale + 1, Position.h * Scale + 1,
             (Position.x - Cam->getCameraPos().x * Speed.x) * Scale,(Position.y - Cam->getCameraPos().y * Speed.y) * Scale);

        SDL_RenderCopy(Renderer, Actor->getTexture(), nullptr, &Pos);
    }
}

void Sadge::SadgeFileMap::CreateMap(SDL_Renderer* Renderer, std::string UpWallPath, std::string SideWallPath, std::string FloorPath, int TileSize) {
    int horLength = 0;
    int maxHorLength = 0;
    int VerLength = 0;
    for(char Character : FileContent) {
        if(Character == '\n')
        {
            if(maxHorLength < horLength){
                maxHorLength = horLength;
            }
            horLength = 0;
            VerLength++;
            continue;
        }
        else if(Character == '|') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(SideWallPath, Renderer);
            SDL_Rect TileRect = SadgeEngineUtils::CreateRect(TileSize, TileSize, TileSize * horLength, TileSize * VerLength);
            SadgeTile Tile(TileTexture, TileRect, Wall);
            MapTiles.push_back(std::make_shared<Sadge::SadgeTile>(Tile));
        }
        else if(Character == '-') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(UpWallPath, Renderer);
            SDL_Rect TileRect = SadgeEngineUtils::CreateRect(TileSize, TileSize, TileSize * horLength, TileSize * VerLength);
            SadgeTile Tile(TileTexture, TileRect, Wall);
            MapTiles.push_back(std::make_shared<Sadge::SadgeTile>(Tile));
        }
        else if(Character == '.') {
            SDL_Texture* TileTexture = SadgeEngineUtils::CreateTexture(FloorPath, Renderer);
            SDL_Rect TileRect = SadgeEngineUtils::CreateRect(TileSize, TileSize, TileSize * horLength, TileSize * VerLength);
            SadgeTile Tile(TileTexture, TileRect, Ground);
            MapTiles.push_back(std::make_shared<Sadge::SadgeTile>(Tile));
        }
        horLength++;
    }
    MapSize = std::make_pair(maxHorLength * TileSize, (VerLength + 1) * TileSize);
}


const std::pair<uint64_t, uint64_t> &Sadge::SadgeFileMap::getMapSize() const {
    return MapSize;
}

const std::vector<std::shared_ptr<Sadge::SadgeActor>> &Sadge::SadgeFileMap::getMapTiles() const {
    return MapTiles;
}

