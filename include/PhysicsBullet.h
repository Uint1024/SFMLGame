#ifndef PHYSICSBULLET_H
#define PHYSICSBULLET_H
#include "PhysicsComponent.h"
#include "PhysicsBullet.h"

class GameObject;
class GameData;
class PhysicsBullet : public PhysicsComponent
{
    public:
        PhysicsBullet(const float angle);
        virtual ~PhysicsBullet();
        virtual bool  Update(GameObject* object,
                             GameData& game_data,
                             ControlsComponent* controls,
                             Engine& engine) ;
    protected:
    private:
        float angle_;
        float distance_travelled_;
        float max_distance_;
        float damage_;
};

#endif // PHYSICSBULLET_H
