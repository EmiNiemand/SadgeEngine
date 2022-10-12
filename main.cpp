#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/Player1.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));


    if(Engine.Start()) {
        SDL_Texture* Player1Texture = Sadge::SadgeEngineUtils::CreateTexture("../png/petrfat.png", Engine.getRenderer());
        SDL_Rect Player1Rect = Sadge::SadgeEngineUtils::CreateRect(200, 200, 50, 0);
        std::shared_ptr<Sadge::SadgePawn> Player1 = std::make_shared<Sadge::Player1>(Player1Texture, &Player1Rect, true);

        Engine.SpawnPawn(Player1);

        Engine.Update();
    }

    return 0;
}
