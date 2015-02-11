#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "GameData.h"

class Engine
{
    public:
        Engine(const sf::VideoMode video_mode, const char* window_name);
        ~Engine();
        void Render(GameData& game_data);
        void MoveCamera(sf::Vector2f& movement);
        void CloseWindow();
        void ZoomIn();
        void ZoomOut();

        //Accessors:
        inline sf::RenderWindow& GetWindow(){
            return window_;
        }

        inline sf::View& GetCamera(){
            return camera_;
        }

    protected:
    private:
        sf::RenderWindow window_;
        sf::View camera_;
};

#endif // ENGINE_H
