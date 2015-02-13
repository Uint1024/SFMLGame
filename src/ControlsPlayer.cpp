#include <SFML/System/Vector2.hpp>
#include "ControlsPlayer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Engine.h"
#include "GameData.h"
#include "GameObject.h"
#include "GraphicsVisible.h"
#include "PhysicsSolid.h"
#include "PhysicsBullet.h"


ControlsPlayer::ControlsPlayer(InputManager& input_manager) :
input_manager_(input_manager)
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
    std::array<bool, kInput_Count>& keys_down =
                            input_manager_.GetKeysDown();

    std::array<bool, kInput_Count>& last_keys_down =
                            input_manager_.GetLastKeysDown();

    object->Move(movement_);
    engine.MoveCamera(movement_);

    movement_ = sf::Vector2f(0.0f,0.0f);

    if(keys_down[kInput_Left]){
        movement_.x -= speed_;
    }

    if(keys_down[kInput_Right]){
        movement_.x += speed_;
    }

    if(keys_down[kInput_Up]){
        movement_.y -= speed_;
    }

    if(keys_down[kInput_Down]){
        movement_.y += speed_;
    }


    sf::Vector2f position = object->getPosition();
    if(keys_down[kInput_Shoot]){
        game_data.GetProjectiles().emplace_back(
                GameObject(object->getPosition(),
                           sf::Vector2f{10,10},
                           new PhysicsBullet(input_manager_.GetAngleToMouse(position)),
                           new GraphicsVisible(kTexture_Ground_Cement)));
    }
}
