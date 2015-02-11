#include <iostream>
#include "Globals.h"
#include "GameData.h"
#include "Engine.h"
#include "InputManager.h"

int main(){


    Engine engine(sf::VideoMode(1280, 768), "Game");
    GameData game_data(engine);
    InputManager input_manager(&engine, &game_data);

    bool running = true;

    sf::Clock frame_timer;
    float g_delta_time = 0.0f;
    while (running)
    {
        g_delta_time = frame_timer.restart().asSeconds();
        if(input_manager.PollEvents() == -1){
            running = false;
            engine.CloseWindow();
        }

        game_data.Update();
        engine.Render(game_data);
    }

    return EXIT_SUCCESS;
}
