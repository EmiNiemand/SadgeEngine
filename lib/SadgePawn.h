//
// Created by szymo on 07/10/2022.
//

#ifndef SADGEENGINE_SADGEPAWN_H
#define SADGEENGINE_SADGEPAWN_H

#include "SadgeActor.h"
#include "Vector2.h"
#include <vector>
#include <memory>

namespace Sadge{
    class SadgePawn : public SadgeActor {
    private:
        Vector2<double> RealPosition;
    protected:
        Vector2<double> Velocity;
        bool bGravityOn;
        float G = -9.81;
    public:
        SadgePawn(SDL_Texture *texture, SDL_Rect shapeAndPosition, bool bGravityOn);
        ~SadgePawn() override;

        virtual void Update(double DeltaTime, std::vector<SDL_Event> &EventList,
                          std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns,
                          std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors);
        virtual void Move(double DeltaTime, std::vector<SDL_Event> &EventList,
                          std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns,
                          std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) = 0;
        virtual void CheckCollision(std::vector<std::shared_ptr<Sadge::SadgePawn>> CollidingPawns) = 0;
        virtual void CheckCollisionActors(std::vector<std::shared_ptr<Sadge::SadgeActor>> CollidingActors) = 0;
        const Vector2<double> &getRealPosition() const;
        void setNewPosition(Vector2<double> position);
    protected:
        void Shift(Vector2<double> vector2);
    };
}


#endif //SADGEENGINE_SADGEPAWN_H
