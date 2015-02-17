#include <string>
#include <SFML/System/Vector2.hpp>
#include "Message.h"

#include "ControlsPlayer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Engine.h"
#include "Globals.h"
#include "GameData.h"
#include "GameObject.h"
#include "GraphicsVisible.h"
#include "PhysicsSolid.h"
#include "PhysicsBullet.h"
#include "Weapon.h"
#include "InventoryComponent.h"


ControlsPlayer::ControlsPlayer(InputManager& input_manager) :
input_manager_(input_manager),
ControlsComponent(false)
{
    //ctor
}

ControlsPlayer::~ControlsPlayer()
{
    //dtor
}

void
ControlsPlayer::Update(GameObject* object, Engine& engine,
                        GameData& game_data){
    //WHAT. THE. FUCK?
    const std::array<bool, kInput_Count>& keys_down =
                            input_manager_.GetKeysDown();

    const std::array<bool, kInput_Count>& last_keys_down =
                            input_manager_.GetLastKeysDown();

    object->Move(movement_);
    engine.MoveCamera(movement_);

    movement_ = sf::Vector2f(0.0f,0.0f);

    if(keys_down[kInput_Left]){
        movement_.x -= speed_ * g_delta_time;
    }

    if(keys_down[kInput_Right]){
        movement_.x += speed_ * g_delta_time;
    }

    if(keys_down[kInput_Up]){
        
        movement_.y -= speed_ * g_delta_time;
    }

    if(keys_down[kInput_Down]){
        movement_.y += speed_ * g_delta_time;
    }
    
    if(keys_down[kInput_Inventory1]){
        object->GetInventory()->SetCurrentWeapon(0);
    }
    if(keys_down[kInput_Inventory2]){
        object->GetInventory()->SetCurrentWeapon(1);
    }

    sf::Vector2f position = object->getPosition();
    if(keys_down[kInput_Shoot] && object->GetInventory()->GetCurrentWeapon()){
        float angle = input_manager_.GetAngleToMouse(position);
        object->GetInventory()->GetCurrentWeapon()
                                ->Shoot(game_data,
                                        input_manager_.GetAngleToMouse(position),
                                        object->getPosition());
    }
    
    for(auto &o : objects_collisions_list_){
        o->ReceiveMessage(Message{object, kMsg_Use, 0, 0});
    }
    
    objects_collisions_list_.clear();
}
