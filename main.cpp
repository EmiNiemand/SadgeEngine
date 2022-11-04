#include "lib/SadgeEngine.h"
#include "lib/SadgeEngineUtils.h"
#include "lib/Player1.h"
#include "lib/Player2.h"
#include <memory>

int main( int arc, char* argv[] ) {

    Sadge::SadgeEngine Engine(std::make_pair(1200, 600));

    if(Engine.Start()) {
        Engine.Update();
    }

    return 0;
}
