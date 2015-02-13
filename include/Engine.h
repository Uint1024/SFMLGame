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
        void Clear();
        void Display();
        void ZoomIn();
        void ZoomOut();


        //Accessors:
        inline sf::RenderWindow& GetWindow(){
            return window_;
        }

        inline sf::View& GetCamera(){
            return camera_;
        }

        inline std::array<sf::Color, kObject_Count>& GetObjectsColors(){
            return objects_colors_;
        }

        inline sf::Vector2u GetWindowSize() const{
            return window_.getSize();
        }
    protected:
    private:
        sf::RenderWindow window_;
        sf::View camera_;
        std::array<sf::Color, kObject_Count> objects_colors_;
};

#endif // ENGINE_H
