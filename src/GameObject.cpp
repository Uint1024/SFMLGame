#include <iostream>
#include "GameObject.h"
#include "Globals.h"
#include "Engine.h"
#include "GameData.h"
#include "Message.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "ControlsComponent.h"
#include "HealthComponent.h"
#include "UseComponent.h"
#include "InventoryComponent.h"
#include "BulletComponent.h"
#include "Maths.h"
 
GameObject::GameObject() :
    physics_(nullptr),
    graphics_(nullptr),
    controls_(nullptr),
    alive_(false),
    health_(nullptr),
    messages_list_{},
    usable_(nullptr),
    inventory_(nullptr),
    bullet_(nullptr)
{
}
    
GameObject::GameObject( sf::Vector2f position,
                        sf::Vector2f dimensions,
                        PhysicsComponent* physics,
                        GraphicsComponent* graphics,
                        UsableComponent* usable,
                        ControlsComponent* controls,
                        HealthComponent* health,
                        InventoryComponent* inventory,
                        BulletComponent* bullet) :
    physics_(physics),
    graphics_(graphics),
    controls_(controls),
    alive_(true),
    bbox_(position, dimensions),
    health_(health),
    messages_list_{},
    usable_(usable),
    inventory_(inventory),
    bullet_(bullet)
{
    
    MoveTo(position);
}



GameObject::~GameObject()
{
    //dtor
}

//return false if the object is dead after update
bool
GameObject::Update(Engine& engine, GameData& game_data){
    bool msg_use = false;
    for(auto it = messages_list_.begin() ;
        it != messages_list_.end() ;){
        
        if((*it).message_id == kMsg_Use){
            if(usable_){
                usable_->Use((*it).sender, this);
            }
            it = messages_list_.erase(it);
            msg_use = true;
        }
        else{
            ++it;
        }
    }
    
    //if no use message is sent and the object is a door, it's close automatically
    //some levers/buttons are also deactivated after a while
    if(!msg_use){
        if(usable_ && usable_->GetState() == kObjectState_Open){
            usable_->SetState(kObjectState_Close);
        }
    }
    if(graphics_){
        graphics_->Update(this, engine);
    }
      
    if(g_game_state == kGameState_Playing){
        if(controls_){
            controls_->Update(this, engine, game_data);
        }

        if(physics_){            
            physics_->Update(this, game_data, controls_, engine);    
        }

        if(health_){
            health_->Update(this);
        }
    }
    if(health_){
        return health_->IsAlive();
    }

    return alive_;
}


void
GameObject::Move(const sf::Vector2f& movement){
    move(movement);
    bbox_.Move(movement);
}

void
GameObject::Move(const sf::Vector2f& movement, const float angle){
    this->setRotation(ConvertRadiansToDegrees(angle));
    //bbox_->rotate();
    move(movement);
    bbox_.Move(movement);
}


void
GameObject::MoveTo(const sf::Vector2f& position){
    this->setPosition(position);
    bbox_.SetPosition(position);
}

void 
GameObject::ReceiveMessage(Message&& message) {
    messages_list_.push_back(message);
}
