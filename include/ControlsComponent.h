#ifndef CONTROLSCOMPONENT_H
#define CONTROLSCOMPONENT_H
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
        ControlsComponent(InputManager& input_manager);
        virtual ~ControlsComponent();
        virtual void Update(GameObject* object, Engine& engine,
                            GameData& game_data) = 0;

        inline sf::Vector2f GetMovement() const {
            return movement_;
        }

        inline void SetMovement(const sf::Vector2f& movement){
            movement_ = movement;
        }
    protected:
        InputManager& input_manager_;

        sf::Vector2f movement_;

    private:

};

#endif // CONTROLSCOMPONENT_H
