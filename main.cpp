#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/SadgeCloud.h"
#include "lib/SadgePetrFat.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));

    if(Engine.Init()){
        SDL_Texture* CloudTexture = Sadge::SadgeEngineUtils::InitTexture("../png/Cloud1.png", Engine.getRenderer());
        SDL_Rect CloudRect = Sadge::SadgeEngineUtils::CreateShapeAndPosition(100, 100, 100, 100);
        std::shared_ptr<Sadge::SadgeActor> Cloud = std::make_shared<Sadge::SadgeCloud>(CloudTexture, &CloudRect);

        SDL_Texture* PetrFatTexture = Sadge::SadgeEngineUtils::InitTexture("../png/petrfat.png", Engine.getRenderer());
        SDL_Rect PetrFatRect = Sadge::SadgeEngineUtils::CreateShapeAndPosition(200, 200, 50, 0);
        std::shared_ptr<Sadge::SadgePawn> PetrFat = std::make_shared<Sadge::SadgePetrFat>(PetrFatTexture, &PetrFatRect);

        Engine.SpawnActor(Cloud);
        Engine.SpawnPawn(PetrFat);
        Engine.Loop();
    }

    return 0;
}
