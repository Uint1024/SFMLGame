#include <iostream>
#include "Globals.h"
#include "GameData.h"
#include "Engine.h"
#include "InputManager.h"
#include <SFML/System/Vector2.hpp>

sf::Vector2u g_tile_size{64,64};
float g_delta_time = 0.0f;

int main(){


    Engine engine(sf::VideoMode(1280, 768), "Game");
    GameData game_data(engine);
    InputManager input_manager(&engine, &game_data);

    bool running = true;

    sf::Clock frame_timer;

    while (running)
    {
        g_delta_time = frame_timer.restart().asSeconds();
        std::cout << g_delta_time << std::endl;
        if(input_manager.PollEvents() == -1){
            running = false;
            engine.CloseWindow();
        }

        game_data.Update();
        engine.Render(game_data);
    }

    return EXIT_SUCCESS;
}
