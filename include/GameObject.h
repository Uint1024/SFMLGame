#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Globals.h"
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Bbox.h"
#include "ControlsComponent.h"


class HealthComponent;
class PhysicsComponent;
class GraphicsComponent;
class Engine;
class GameData;

class GameObject : public sf::Transformable
{
    public:

        GameObject(sf::Vector2f position,
                   PhysicsComponent* physics,
                   GraphicsComponent* graphics);

        GameObject(sf::Vector2f position,
                       sf::Vector2f dimensions,
                       PhysicsComponent* physics,
                       GraphicsComponent* graphics);

        GameObject(sf::Vector2f position,
                   sf::Vector2f dimensions,
                   PhysicsComponent* physics,
                   GraphicsComponent* graphics,
                   ControlsComponent* controls);
        virtual ~GameObject();
        bool Update(Engine& engine, GameData& game_data);
        void Move(const sf::Vector2f& movement);
        void MoveTo(const sf::Vector2f& position);
        //void SendMessage();

        //Accessors
        inline eObjectType GetType() const{
            return type;
        };


        inline ControlsComponent* GetControls() {
          return controls_;
        };

        inline Die() {
            alive_ = false;
        }

        inline Bbox& GetBbox() {
            return bbox_;
        }

        inline void SetControls(ControlsComponent* controls){
            delete controls_;
            controls_ = nullptr;
            controls_ = controls;
        }

    protected:

    private:
        eObjectType type;
        Bbox bbox_;
        //tentative de component system
        PhysicsComponent* physics_;
        GraphicsComponent* graphics_;
        ControlsComponent* controls_;
        HealthComponent* health_;
        bool alive_;

};

#endif // GAMEOBJECT_H
