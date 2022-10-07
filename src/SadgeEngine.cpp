#include "../lib/SadgeEngine.h"


Sadge::SadgeEngine::SadgeEngine(const std::pair<uint16_t, uint16_t> &Resolution) : Resolution(Resolution) {}

bool Sadge::SadgeEngine::Init() {
    //Create window
    Window = SDL_CreateWindow("The Saddest Window Ever", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               Resolution.first, Resolution.second, SDL_WINDOW_SHOWN);

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
            //Initialize renderer color
            SDL_SetRenderDrawColor( Renderer, 0x20, 0x20, 0x20, 0xFF);
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return false;
            }
        }
    }
    return true;
}

void Sadge::SadgeEngine::Loop() {

    //Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT){
                quit = true;
                End();
            }
        }
        //Clear screen
        SDL_RenderClear(Renderer);

        for(std::shared_ptr<SadgePawn> Pawn : Pawns) {
            Pawn->Update();
            SDL_Rect* Position = Pawn->getShapeAndPosition();
            if(Position->y > Resolution.second - Position->h) {
                Pawn->setNewPosition(Position->x, Resolution.second - Position->h);
            }
            SDL_RenderCopy(Renderer, Pawn->getTexture(), nullptr, Pawn->getShapeAndPosition());
        }

        for(std::shared_ptr<SadgeActor> Actor : Actors) {
            SDL_RenderCopy(Renderer, Actor->getTexture(), nullptr, Actor->getShapeAndPosition());
        }

        //Update screen
        SDL_RenderPresent(Renderer);

        SDL_Delay(20);
    }
}

void Sadge::SadgeEngine::End() {
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

SDL_Renderer *Sadge::SadgeEngine::getRenderer() const {
    return Renderer;
}

void Sadge::SadgeEngine::SpawnActor(std::shared_ptr<SadgeActor> Actor) {
    Actors.push_back(Actor);
}

void Sadge::SadgeEngine::SpawnPawn(std::shared_ptr<SadgePawn> Pawn) {
    Pawns.push_back(Pawn);
}

