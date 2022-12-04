/*
//
// Created by szymo on 16/11/2022.
//

#ifndef SADGEENGINE_BALL_H
#define SADGEENGINE_BALL_H

#include "SadgePawn.h"

namespace Sadge{
    class Ball : public SadgePawn{
    private:
        float Speed;
        Vector2<double> Direction;
        bool CollisionEnabled = true;
        bool SeparationEnabled = true;

    public:
        Ball(SDL_Texture *texture, const SDL_Rect &shapeAndPosition, bool bGravityOn, double speed,
             const Vector2<double> &direction);

        ~Ball() override;

        void Update(double DeltaTime, std::vector<SDL_Event> &EventList) override;
        void Move(double DeltaTime, std::vector<SDL_Event> &EventList) override;

        void setDirection(const Vector2<double> &direction);

        const Vector2<double> &getDirection() const;

        void EventHandler(std::vector<SDL_Event> &EventList);

        void CheckCollision(std::shared_ptr<Sadge::SadgePawn> CollidingPawn, std::pair<uint16_t, uint16_t> WindowResolution) override;
    };
}


#endif //SADGEENGINE_BALL_H
*/
