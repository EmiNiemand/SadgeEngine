#include "../lib/SadgeEngine.h"
#include "chrono"
#include <iostream>
#include <math.h>

Sadge::SadgeEngine::SadgeEngine(const std::pair<uint16_t, uint16_t> &WindowResolution) : WindowResolution(WindowResolution) {}

Sadge::SadgeEngine::~SadgeEngine() {
    for(std::shared_ptr<SadgePawn> Pawn : Pawns) {
        SDL_DestroyTexture(Pawn->getTexture());
    }

    for(std::shared_ptr<SadgeActor> Actor : Actors) {
        SDL_DestroyTexture(Actor->getTexture());
    }

    //Destroy window
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

bool Sadge::SadgeEngine::Start() {
    //Create window
    Window = SDL_CreateWindow("The Saddest Window Ever", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WindowResolution.first, WindowResolution.second, SDL_WINDOW_SHOWN);

    if(Window == nullptr) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    else {
        //Create renderer for window
        Renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED );
        if(Renderer == nullptr) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
        }
        else {
            //Start renderer color
            SDL_SetRenderDrawColor( Renderer, 0x60, 0x60, 0x60, 0xFF);
            //Start PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return false;
            }
        }
    }
    return true;
}

void Sadge::SadgeEngine::Update() {
    auto StartTime = std::chrono::high_resolution_clock::now();
    auto FrameEndTime = StartTime;
    std::chrono::duration<double> DeltaTime{};
    float Scale = 1;

    std::vector<SadgeFileMap> Maps;

    SadgeFileMap Map1("../png/Map");
    Map1.CreateMap(Renderer, "../png/TileUpperWall.png", "../png/TileSideWall.png", "../png/TileFloor.png", 50);
    for (std::shared_ptr<SadgeActor> Actor : Map1.getMapTiles()){
        SpawnActor(Actor);
    }

    Maps.push_back(Map1);

    SDL_Rect CamRect = SadgeEngineUtils::CreateRect(WindowResolution.first, WindowResolution.second, 0, 0);
    Camera Cam(CamRect, Map1.getMapSize());
    SDL_Texture* Player1Texture = Sadge::SadgeEngineUtils::CreateTexture("../png/Vent.png", Renderer);
    SDL_Rect Player1Rect = Sadge::SadgeEngineUtils::CreateRect(40, 40, WindowResolution.first / 2 - 50, WindowResolution.second / 2 - 50);
    std::shared_ptr<Sadge::SadgePawn> Player1 = std::make_shared<Sadge::Player1>(Player1Texture, Player1Rect, true, 250);

    SpawnPawn(Player1);

    //Hack to get window to stay up
    SDL_Event e;
    std::vector<SDL_Event> Events;
    bool quit = false;
    while(!quit) {
        auto FrameStartTime = std::chrono::high_resolution_clock::now();
        while(SDL_PollEvent(&e)) {
            Events.push_back(e);
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        //Clear screen
        SDL_RenderClear(Renderer);

        Cam.Update(Pawns.at(0));

        for(std::shared_ptr<SadgeActor> Actor : Actors) {
            auto Position = Actor->getShapeAndPosition();
            SDL_Rect Pos;
            Pos = SadgeEngineUtils::CreateRect(Position.w * Scale + 1, Position.h * Scale + 1,
                    (Position.x - Cam.getCameraPos().x) * Scale,(Position.y - Cam.getCameraPos().y) * Scale);

            SDL_RenderCopy(Renderer, Actor->getTexture(), nullptr, &Pos);
        }

        for(std::shared_ptr<SadgePawn> Pawn : Pawns) {
            Pawn->Update(DeltaTime.count(), Events, Pawns, Actors);
            auto Position = Pawn->getShapeAndPosition();
            SDL_Rect Pos;
            Pos = SadgeEngineUtils::CreateRect(Position.w * Scale + 1, Position.h * Scale + 1,
                   (Position.x - Cam.getCameraPos().x) * Scale,(Position.y - Cam.getCameraPos().y) * Scale);
            SDL_RenderCopy(Renderer, Pawn->getTexture(), nullptr, &Pos);
        }

        if (DeltaTime.count() < 0.016) {
            SDL_Delay(16 - DeltaTime.count() * 1000);
        }
        //Update screen
        SDL_RenderPresent(Renderer);
        DeltaTime = std::chrono::high_resolution_clock::now() - FrameEndTime;
        FrameEndTime = std::chrono::high_resolution_clock::now();
        Events.clear();
    }
}

SDL_Renderer *Sadge::SadgeEngine::getRenderer() const {
    return Renderer;
}

void Sadge::SadgeEngine::SpawnActor(std::shared_ptr<SadgeActor> Actor) {
    Actors.push_back(Actor);
}

void Sadge::SadgeEngine::SpawnPawn(std::shared_ptr<SadgePawn> Pawn) {
    Pawns.push_back(Pawn);
}

const std::pair<uint16_t, uint16_t> &Sadge::SadgeEngine::getWindowResolution() const {
    return WindowResolution;
}

