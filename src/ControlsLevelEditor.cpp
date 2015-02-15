#include <array>
#include <SFML/System/Vector2.hpp>
#include "GameObject.h"
#include "Engine.h"

#include "InputEnum.h"
#include "InputManager.h"
#include "ControlsLevelEditor.h"

ControlsLevelEditor::ControlsLevelEditor(InputManager& input_manager) :
ControlsComponent(false),
input_manager_(input_manager)

{
    //ctor
}

ControlsLevelEditor::~ControlsLevelEditor()
{
    //dtor
}

void
ControlsLevelEditor::Update(GameObject* object, Engine& engine,
                        GameData& game_data){
    std::array<bool, kInput_Count>& keys_down =
                            input_manager_.GetKeysDown();

    std::array<bool, kInput_Count>& last_keys_down =
                            input_manager_.GetLastKeysDown();

    sf::Vector2f movement = sf::Vector2f(0.0f,0.0f);

    if(keys_down[kInput_Left]){
        movement.x -= speed_;
    }
    if(keys_down[kInput_Right]){
        movement.x += speed_;
    }
    if(keys_down[kInput_Up]){
        movement.y -= speed_;
    }
    if(keys_down[kInput_Down]){
        movement.y += speed_;
    }

    object->Move(movement);

    engine.MoveCamera(movement);

    sf::Vector2f position = object->getPosition();

    if(keys_down[kInput_Inventory1]){
        le_selected_object_ = kObject_Ground;
    }
    if(keys_down[kInput_Inventory2]){
        le_selected_object_ = kObject_Wall;
    }
    if(keys_down[kInput_Inventory3]){
        le_selected_object_ = kObject_Guard;
    }
    if(keys_down[kInput_Inventory4]){
        le_selected_object_ = kObject_Door;
    }
    if(keys_down[kInput_Inventory5]){
        le_selected_object_ = kObject_Chest;
    }

    if(keys_down[kInput_Shoot]){
        game_data.CreateObjectAtMousePosition(le_selected_object_);
    }
    
    objects_collisions_list_.clear();
}
