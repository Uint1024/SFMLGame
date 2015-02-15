#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <SFML/System/Vector2.hpp>
#include "Bbox.h"

class GameData;
class GameObject;
class Engine;
class ControlsComponent;
class PhysicsComponent
{
    public:
        PhysicsComponent();
        virtual ~PhysicsComponent();
        virtual bool Update(GameObject* object,
                            GameData& game_data,
                            ControlsComponent* controls,
                            Engine& engine) = 0;
        //virtual CheckCollision() = 0;
    protected:


    private:
};

#endif // PHYSICSCOMPONENT_H
