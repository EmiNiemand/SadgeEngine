#ifndef SADGEENGINE_SADGEENGINE_H
#define SADGEENGINE_SADGEENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <list>
#include <iostream>
#include "SDL.h"
#include "SadgeActor.h"
#include "SadgePawn.h"

namespace Sadge {
    class SadgeEngine {
    private:
        // Window resolution
        std::pair<uint16_t, uint16_t> Resolution;
        // Pointer to window
        SDL_Window* Window;
        // Pointer to renderer
        SDL_Renderer* Renderer;
        // Spawned actors
        std::list<std::shared_ptr<SadgeActor>> Actors;
        // Spawned pawns
        std::list<std::shared_ptr<SadgePawn>> Pawns;

    public:
        explicit SadgeEngine(const std::pair<uint16_t, uint16_t> &Resolution = std::make_pair(640, 480));

        // Initialize window, renderer, etc.
        bool Init();
        // Frame update
        void Loop();
        // Release resources on loop end
        void End();

        SDL_Renderer *getRenderer() const;

        void SpawnActor(std::shared_ptr<SadgeActor> Actor);
        void SpawnPawn(std::shared_ptr<SadgePawn> Pawn);
    };
}

#endif //SADGEENGINE_SADGEENGINE_H
