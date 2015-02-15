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
        sf::RenderWindow& GetWindow(){
            return window_;
        }

        sf::View& GetCamera(){
            return camera_;
        }

        std::array<sf::Color, kTexture_Count>& GetObjectsColors(){
            return objects_colors_;
        }

        sf::Vector2u GetWindowSize() const{
            return window_.getSize();
        }
        
        void CenterCameraOnPlayer(sf::Vector2f player_position);
    protected:
    private:
        sf::RenderWindow window_;
        sf::View camera_;
        std::array<sf::Color, kTexture_Count> objects_colors_;
};

#endif // ENGINE_H
