#ifndef CONTROLSCOMPONENT_H
#define CONTROLSCOMPONENT_H
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class InputManager;
class GameObject;
class Engine;
class GameData;
class PhysicsComponent;
class ControlsComponent
{
    public:
        ControlsComponent();
        virtual ~ControlsComponent();
        virtual void Update(GameObject* object, Engine& engine,
                            GameData& game_data) = 0;
        
        //physics component add the colliding objects to the controls component
        //then the controls can interact with it (like if it's a chest, a door,
        //a health item, a weapon to pickup etc.)
        void AddObjectCollision(GameObject* wall);
        sf::Vector2f GetMovement() const {
            return movement_;
        }

        void SetMovement(const sf::Vector2f& movement){
            movement_ = movement;
        }
    protected:
        sf::Vector2f movement_;
        std::list<GameObject*> objects_collisions_list_;
    private:

};

#endif // CONTROLSCOMPONENT_H
