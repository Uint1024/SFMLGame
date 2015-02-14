#include <iostream>
#include <cmath>
#include "InputManager.h"
#include "SFML/Window/Event.hpp"

#include "Engine.h"
#include "GameData.h"
#include "Globals.h"


InputManager::InputManager() :
    mouse_position_world_(0.0f,0.0f),
    le_selected_object_(kObject_Ground)
{
    for(int i = 0 ; i < kInput_Count ; ++i){
        keyboard_mapping_[i] = sf::Keyboard::Unknown;
    }

    for(int i = 0 ; i < kInput_Count ; ++i){
        mouse_mapping_[i] = sf::Mouse::ButtonCount;
    }

    keyboard_mapping_[kInput_Right] = sf::Keyboard::D;
    keyboard_mapping_[kInput_Left] = sf::Keyboard::Q;
    keyboard_mapping_[kInput_Up] = sf::Keyboard::Z;
    keyboard_mapping_[kInput_Down] = sf::Keyboard::S;
    keyboard_mapping_[kInput_ToggleLevelEditor] = sf::Keyboard::R;
    keyboard_mapping_[kInput_Inventory1] = sf::Keyboard::Num1;
    keyboard_mapping_[kInput_Inventory2] = sf::Keyboard::Num2;
    keyboard_mapping_[kInput_Inventory3] = sf::Keyboard::Num3;
    keyboard_mapping_[kInput_Inventory4] = sf::Keyboard::Num4;
    keyboard_mapping_[kInput_Inventory5] = sf::Keyboard::Num5;
    keyboard_mapping_[kInput_Inventory6] = sf::Keyboard::Num6;
    keyboard_mapping_[kInput_Inventory7] = sf::Keyboard::Num7;
    keyboard_mapping_[kInput_Inventory8] = sf::Keyboard::Num8;
    keyboard_mapping_[kInput_Inventory9] = sf::Keyboard::Num9;
    mouse_mapping_[kInput_Shoot] = sf::Mouse::Left;
}

InputManager::~InputManager()
{
    //dtor
}

int
InputManager::PollEvents(Engine& engine, GameData& game_data){
    sf::Vector2i mouse_position_window;

    mouse_position_window = sf::Mouse::getPosition(engine.GetWindow());


    keys_down_[kInput_ZoomIn] = false;
    keys_down_[kInput_ZoomOut] = false;

    sf::Event event;
    sf::RenderWindow& window = engine.GetWindow();

    mouse_position_world_ = window.mapPixelToCoords(mouse_position_window);

    mouse_tile_position_in_tiles_ =
            sf::Vector2u{static_cast<unsigned int>
                            (mouse_position_world_.x / g_tile_size.x),
                         static_cast<unsigned int>
                            (mouse_position_world_.y / g_tile_size.y)};

    mouse_tile_position_in_pixels_ =
            sf::Vector2u{static_cast<unsigned int>
                            (mouse_tile_position_in_tiles_.x * g_tile_size.x),
                         static_cast<unsigned int>
                            (mouse_tile_position_in_tiles_.y * g_tile_size.y)};

    for(int i = 0 ; i < kInput_Count ; ++i){
        if(sf::Keyboard::isKeyPressed(keyboard_mapping_[i]) ||
           sf::Mouse::isButtonPressed(mouse_mapping_[i])){
            keys_down_[i] = true;
        } else {
            keys_down_[i] = false;
        }
    }

    while (window.pollEvent(event))
    {
        switch(event.type) {
            case sf::Event::Closed:
                return -1;
                break;

            case sf::Event::MouseWheelMoved:
                if(event.mouseWheel.delta > 0){
                    keys_down_[kInput_ZoomOut] = true;
                }
                else {
                    keys_down_[kInput_ZoomIn] = true;
                }
                break;
        }

    }




    GameObject& player = game_data.GetPlayer();
/*    if(movement.x || movement.y){
        //engine.MoveCamera(movement);
        //player.Move(movement);
    }*/


    if(keys_down_[kInput_ZoomIn]){
        engine.ZoomIn();
    }
    if(keys_down_[kInput_ZoomOut]){
        engine.ZoomOut();
    }

    if(keys_down_[kInput_ToggleLevelEditor] &&
       !last_keys_down_[kInput_ToggleLevelEditor]){
        game_data.ToggleLevelEditorMode();
    }


    /*if(game_data.GetGameState() == kGameState_Editor){
        if(keys_down_[kInput_Inventory1]){
            le_selected_object_ = kObject_Ground_Grass;
        }
        if(keys_down_[kInput_Inventory2]){
            le_selected_object_ = kObject_Wall_Black;
        }
        if(keys_down_[kInput_Inventory3]){
            le_selected_object_ = kObject_Ground_BlueCarpet;
        }
        if(keys_down_[kInput_Inventory4]){
            le_selected_object_ = kObject_Ground_BlueCarpet;
        }
        EditLevel(game_data);
    }
    else{
        Play(game_data);
    }*/

    last_keys_down_ = keys_down_;

    return 1;
}

void
InputManager::Play(GameData& game_data){

}

void
InputManager::EditLevel(GameData& game_data){
    /*if(keys_down_[kInput_Shoot]){
        game_data.CreateMapGridObject(le_selected_object_,
                                mouse_tile_position_in_tiles_);
    }*/
}

float
InputManager::GetAngleToMouse(const sf::Vector2f& object_pos)
{
    return atan2(mouse_position_world_.y - object_pos.y,
              mouse_position_world_.x - object_pos.x);
}
