#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/Player1.h"
#include "lib/Player2.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));


    if(Engine.Start()) {
        SDL_Texture* Player1Texture = Sadge::SadgeEngineUtils::CreateTexture("../png/Vent.png", Engine.getRenderer());
        SDL_Rect Player1Rect = Sadge::SadgeEngineUtils::CreateRect(50, 50, 500, 500);
        std::shared_ptr<Sadge::SadgePawn> Player1 = std::make_shared<Sadge::Player1>(Player1Texture, &Player1Rect, false, 2);

        SDL_Texture* Player2Texture = Sadge::SadgeEngineUtils::CreateTexture("../png/circle.png", Engine.getRenderer());
        SDL_Rect Player2Rect = Sadge::SadgeEngineUtils::CreateRect(100, 100, 500, 500);
        std::shared_ptr<Sadge::SadgePawn> Player2 = std::make_shared<Sadge::Player2>(Player2Texture, &Player2Rect, false);


        Engine.SpawnPawn(Player1);
        Engine.SpawnPawn(Player2);
        Engine.Update();
    }

    return 0;
}
