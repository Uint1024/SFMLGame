#include <iostream>
#include "Globals.h"
#include "GameData.h"
#include "Engine.h"
#include "InputManager.h"
#include <SFML/System/Vector2.hpp>

sf::Vector2f g_tile_size{64,64};
float g_delta_time = 0.0f;
float PI = 3.14;
int g_game_time = 0;
eGameState g_game_state = kGameState_Playing;
int main(){


    Engine engine(sf::VideoMode(1280, 768), "Game");

    InputManager input_manager;
    GameData game_data(engine, input_manager);


    bool running = true;

    sf::Clock frame_timer;
    sf::Clock game_timer;
    while (running)
    {
        
        g_delta_time = frame_timer.restart().asSeconds();
        g_game_time = game_timer.getElapsedTime().asMilliseconds();
        if(game_data.Update() == -1){
            running = false;
        }
    }

    engine.CloseWindow();

    return EXIT_SUCCESS;
}
