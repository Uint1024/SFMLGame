#include <iostream>
#include <cmath>
#include "InputManager.h"
#include "SFML/Window/Event.hpp"

#include "Engine.h"
#include "GameData.h"
#include "Player.h"

InputManager::InputManager(Engine* engine, GameData* game_data) :
    engine_(engine), game_data_(game_data)
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

    sf::Vector2f  mouse_position_world = window.mapPixelToCoords(mouse_position_window);
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

    Player& player = game_data_->GetPlayer();

    if(movement.x || movement.y){
        engine_->MoveCamera(movement);
        player.Move(movement);
    }

    if(keys_down_[kInput_Shoot]){
        float angle_to_mouse =
                atan2(mouse_position_world.y - player.GetPosition().y,
                      mouse_position_world.x -  player.GetPosition().x);
        game_data_->PlayerShoots(angle_to_mouse);
    }

    if(keys_down_[kInput_ZoomIn]){
        engine_->ZoomIn();
    }
    if(keys_down_[kInput_ZoomOut]){
        engine_->ZoomOut();
    }

    return 1;
}
