#ifndef PHYSICSBULLET_H
#define PHYSICSBULLET_H
#include <array>
#include "PhysicsComponent.h"
#include "PhysicsBullet.h"

class GameObject;
class GameData;
class PhysicsBullet : public PhysicsComponent
{
    public:
        PhysicsBullet(const float angle, const float speed);
        virtual ~PhysicsBullet();
        virtual bool  Update(GameObject* object,
                             GameData& game_data,
                             ControlsComponent* controls,
                             Engine& engine) ;
    protected:
    private:
        float angle_;
        float distance_travelled_per_tick_;
        float distance_travelled_;
        float max_distance_;
        float speed_;
        sf::Vector2f movement_;
        sf::Vector2f velocity_;
        eDirection direction_of_collision_;
        std::array<Bbox*, kDirection_Count> collisions_in_4_directions_;
        std::array<int, kDirection_Count> nb_of_collisions_in_4_directions_;
};

#endif // PHYSICSBULLET_H
