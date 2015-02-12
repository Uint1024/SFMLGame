#include <iostream>
#include <cmath>
#include "InputManager.h"
#include "SFML/Window/Event.hpp"

#include "Engine.h"
#include "GameData.h"

InputManager::InputManager(Engine* engine, GameData* game_data) :
    engine_(engine), game_data_(game_data), mouse_position_world_(0.0f,0.0f),
    player_(game_data_->GetPlayer()), le_selected_object_(kOBject_Ground_Grass)
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
    mouse_mapping_[kInput_Shoot] = sf::Mouse::Left;
}

InputManager::~InputManager()
{
    //dtor
}

int
InputManager::PollEvents(){
    sf::Vector2i mouse_position_window;


    mouse_position_window = sf::Mouse::getPosition(engine_->GetWindow());


    keys_down_[kInput_ZoomIn] = false;
    keys_down_[kInput_ZoomOut] = false;

    sf::Event event;
    sf::RenderWindow& window = engine_->GetWindow();

    mouse_position_world_ = window.mapPixelToCoords(mouse_position_window);
    mouse_tile_position_in_tiles_ =
            sf::Vector2u{static_cast<unsigned int>
                            (mouse_position_world_.x / g_tile_size.x),
                         static_cast<unsigned int>
                            (mouse_position_world_.y / g_tile_size.y)};

    mouse_tile_position_in_pixels_ =
            sf::Vector2u{mouse_tile_position_in_tiles_.x * g_tile_size.x,
                         mouse_tile_position_in_tiles_.y * g_tile_size.y};

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

    sf::Vector2f movement = {0.0f,0.0f};

    if(keys_down_[kInput_Left]){
        movement.x -= 10;
    }
    if(keys_down_[kInput_Right]){
        movement.x += 10;
    }
    if(keys_down_[kInput_Up]){
        movement.y -= 10;
    }
    if(keys_down_[kInput_Down]){
        movement.y += 10;
    }



    if(movement.x || movement.y){
        engine_->MoveCamera(movement);
        player_.Move(movement);
    }


    if(keys_down_[kInput_ZoomIn]){
        engine_->ZoomIn();
    }
    if(keys_down_[kInput_ZoomOut]){
        engine_->ZoomOut();
    }

    if(keys_down_[kInput_ToggleLevelEditor]){
        game_data_->ToggleLevelEditorMode();
    }

    if(game_data_->GetGameState() == kGameState_Editor){
        EditLevel();
    }
    else{
        Play();
    }

    return 1;
}

void
InputManager::Play(){
    if(keys_down_[kInput_Shoot]){
        float angle_to_mouse =
                atan2(mouse_position_world_.y - player_.GetPosition().y,
                      mouse_position_world_.x -  player_.GetPosition().x);
        game_data_->PlayerShoots(angle_to_mouse);
    }
}

void
InputManager::EditLevel(){
    if(keys_down_[kInput_Shoot]){
        game_data_->CreateMapGridObject(le_selected_object_,
                                mouse_tile_position_in_tiles_);
    }
}
