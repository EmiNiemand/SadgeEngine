//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEPAWN_H
#define SADGEENGINE_SADGEPAWN_H

#include "SadgeActor.h"
#include <vector>

namespace Sadge{
    class SadgePawn : public SadgeActor {
    private:
        std::pair<double, double> RealPosition;
        bool bGravityOn;
    public:
        SadgePawn(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn);
        ~SadgePawn() override;

        virtual void Update(double DeltaTime, std::vector<SDL_Event> &EventList);
        virtual void Move(double DeltaTime, std::vector<SDL_Event> &EventList) = 0;
        const std::pair<double, double> &getRealPosition() const;
        void setNewPosition(double x, double y);
    protected:
        void Shift(double x, double y);
    };
}


#endif //SADGEENGINE_SADGEPAWN_H
