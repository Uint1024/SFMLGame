#include <iostream>
#include "Engine.h"

Engine::Engine(const sf::VideoMode video_mode, const char* window_name) :
    window_(video_mode, window_name),
    camera_(sf::FloatRect(0, 0, 1280, 768))
{
    window_.setVerticalSyncEnabled(true);
    window_.setView(camera_);
    objects_colors_[kTexture_Ground_Dirt] =  sf::Color{96,27,26};
    objects_colors_[kTexture_Ground_Grass] =  sf::Color{96,27,180};
    objects_colors_[kTexture_Ground_Cement] =  sf::Color{100,100,100};
    objects_colors_[kTexture_Ground_BlueCarpet] =  sf::Color{30,200,36};
}

Engine::~Engine()
{
    //dtor
}



void
Engine::Render(GameData& game_data){
    window_.clear();
    window_.setView(camera_);

    sf::Vector2u map_size = game_data.GetMapSizeInPixels();
    sf::Vector2u tile_size = game_data.GetTileSize();

    for(unsigned int y = 0 ; y < map_size.y ; y += tile_size.y){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, y)),
            sf::Vertex(sf::Vector2f(map_size.x, y))
        };
        window_.draw(line, 2, sf::Lines);
    }
    for(unsigned int x = 0 ; x < map_size.x ; x += tile_size.x){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, 0)),
            sf::Vertex(sf::Vector2f(x, map_size.y))
        };
        window_.draw(line, 2, sf::Lines);
    }
    auto& projectiles = game_data.GetProjectiles();
    auto& walls = game_data.GetWalls();
    auto& ground = game_data.GetGround();

    int total_tiles = game_data.GetTotalTiles();
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f{static_cast<float>(g_tile_size.x),
                  static_cast<float>(g_tile_size.y)});

    int x, y = 0;
    for(int i = 0 ; i < total_tiles ; i++, x++){
        if(walls[i]){
            //window_.draw(*walls[i]);
        }

        if(ground[i]){
                std::cout << x * g_tile_size.x << std::endl;
            shape.setPosition(sf::Vector2f{static_cast<float>(x * g_tile_size.x),
                              static_cast<float>(y * g_tile_size.y)});
            shape.setFillColor(objects_colors_[ground[i]->GetTextureId()]);
            window_.draw(shape);
        }

        if(x == game_data.GetMapSizeInTiles().x){
            x = 0;
            ++y;
        }
    }

    for(auto &o : projectiles){
        window_.draw(o);
    }

    window_.draw(game_data.GetPlayer());
    window_.display();
}


void
Engine::CloseWindow(){
    window_.close();
}

void
Engine::MoveCamera(sf::Vector2f& movement)
{
    camera_.move(movement);
}

void
Engine::ZoomIn(){
    camera_.zoom(1.1f);
}

void
Engine::ZoomOut(){
    camera_.zoom(0.9f);
}

