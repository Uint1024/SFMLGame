#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include "Message.h"
#include "Globals.h"
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Bbox.h"
#include "ControlsComponent.h"

class InventoryComponent;
class HealthComponent;
class UsableComponent;
class PhysicsComponent;
class GraphicsComponent;
class Engine;
class GameData;

class GameObject : public sf::Transformable
{
    public:        
        GameObject(sf::Vector2f position,
                   sf::Vector2f dimensions,
                   PhysicsComponent* physics,
                   GraphicsComponent* graphics,
                UsableComponent* usable,
                   ControlsComponent* controls = nullptr,
                   HealthComponent* health = nullptr,
                InventoryComponent* inventory = nullptr);
        
        virtual ~GameObject();
        bool Update(Engine& engine, GameData& game_data);
        void Move(const sf::Vector2f& movement);
        void MoveTo(const sf::Vector2f& position);
        void ReceiveMessage(Message&& message);
        
        //Accessors
        eObjectType GetType() const{
            return type;
        };


        ControlsComponent* GetControls() {
          return controls_;
        };
        
        HealthComponent* GetHealth(){
            return health_;
        }
        
        UsableComponent* GetUsable() const {
            return usable_;
        }

        

         Die() {
            alive_ = false;
        }

        Bbox& GetBbox() {
            return bbox_;
        }

        void SetControls(ControlsComponent* controls){
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
        InventoryComponent* inventory_;
        //for doors, health pack, levers, chests...
        UsableComponent* usable_;
        bool alive_;
        std::list<Message> messages_list_;

};

#endif // GAMEOBJECT_H
