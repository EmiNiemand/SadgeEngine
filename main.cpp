#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/Player1.h"
#include "lib/Player2.h"
#include "lib/Ball.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));

    srand(time(NULL));
    if(Engine.Start()) {
        SDL_Texture* BallTexture = Sadge::SadgeEngineUtils::CreateTexture("../png/circle.png", Engine.getRenderer());
        for(int i = 0; i < 50; i++) {

            SDL_Rect BallRect = Sadge::SadgeEngineUtils::CreateRect(50, 50, rand() % (Engine.getWindowResolution().first - 25) + 25,
                                                            rand() % (Engine.getWindowResolution().second - 25) + 25);
            std::shared_ptr<Sadge::SadgePawn> Ball = std::make_shared<Sadge::Ball>(BallTexture, BallRect, false,
                                             (float)((rand() % 10) + 1) / 10, Vector2<double>(rand() % 2 + 1, rand() % 2 + 1));
            Engine.SpawnPawn(Ball);
        }

        Engine.Update();
    }

    return 0;
}
