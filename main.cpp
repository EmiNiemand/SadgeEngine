#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/SadgeCloud.h"
#include "lib/SadgePetrFat.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));

    if(Engine.Start()){
        SDL_Texture* CloudTexture = Sadge::SadgeEngineUtils::CreateTexture("../png/Cloud1.png", Engine.getRenderer());
        SDL_Rect CloudRect = Sadge::SadgeEngineUtils::CreateRect(100, 100, 100, 100);
        std::shared_ptr<Sadge::SadgeActor> Cloud = std::make_shared<Sadge::SadgeCloud>(CloudTexture, &CloudRect);

        SDL_Texture* PetrFatTexture = Sadge::SadgeEngineUtils::CreateTexture("../png/petrfat.png", Engine.getRenderer());
        SDL_Rect PetrFatRect = Sadge::SadgeEngineUtils::CreateRect(200, 200, 50, 0);
        std::shared_ptr<Sadge::SadgePawn> PetrFat = std::make_shared<Sadge::SadgePetrFat>(PetrFatTexture, &PetrFatRect);

        Engine.SpawnActor(Cloud);
        Engine.SpawnPawn(PetrFat);
        Engine.Update();
    }

    return 0;
}
