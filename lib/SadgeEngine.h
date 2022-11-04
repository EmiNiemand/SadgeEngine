#ifndef SADGEENGINE_SADGEENGINE_H
#define SADGEENGINE_SADGEENGINE_H

#include "SDL.h"
#include "SadgeActor.h"
#include "SadgePawn.h"
#include "SadgeEngineUtils.h"
#include "Player1.h"
#include "Player2.h"
#include "SadgeFileMap.h"
#include "Camera.h"
#include "CameraForBothPlayers.h"

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <list>

namespace Sadge {
    class SadgeEngine {
    private:
        // Window resolution
        std::pair<uint16_t, uint16_t> WindowResolution;
        // Pointer to window
        SDL_Window* Window;
        // Pointer to renderer
        SDL_Renderer* Renderer;
        // Spawned actors
        std::vector<std::shared_ptr<SadgeActor>> Actors;
        // Spawned pawns
        std::vector<std::shared_ptr<SadgePawn>> Pawns;

    public:
        explicit SadgeEngine(const std::pair<uint16_t, uint16_t> &WindowResolution = std::make_pair(640, 480));
        // Release resources
        virtual ~SadgeEngine();

        // Start window, renderer, etc.
        bool Start();
        // Frame update
        void Update();

        SDL_Renderer *getRenderer() const;

        void SpawnActor(std::shared_ptr<SadgeActor> Actor);
        void SpawnPawn(std::shared_ptr<SadgePawn> Pawn);

        const std::pair<uint16_t, uint16_t> &getWindowResolution() const;
    };
}

#endif //SADGEENGINE_SADGEENGINE_H
