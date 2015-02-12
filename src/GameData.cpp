#include <iostream>

#include "GameData.h"
#include "Engine.h"

inline sf::Vector2f
ConvertTilePositionToPixels(const sf::Vector2u& tile_position){
    return {static_cast<float>(tile_position.x * g_tile_size.x),
            static_cast<float>(tile_position.y + g_tile_size.y)};
}

GameData::GameData(Engine& engine) :
    map_size_tiles_(100,100),
    tile_size_(64,64),
    engine_(engine),
    game_state_(kGameState_Editor),
    ground_dirt_model(kTexture_Ground_Dirt),
    ground_grass_model(kTexture_Ground_Grass)
{
    sf::Vector2u window_size = engine_.GetWindow().getSize();
    player_ = Player(sf::Vector2f{   static_cast<float>(window_size.x/2),
                            static_cast<float>(window_size.y/2)});

    map_size_pixels_ = sf::Vector2u(map_size_tiles_.x * tile_size_.x,
                                    map_size_tiles_.y * tile_size_.y);

    total_tiles_ = map_size_tiles_.x * map_size_tiles_.y;


    for(int i = 0 ; i < total_tiles_ ; ++i){
        wall_map_.push_back(nullptr);
        ground_map_.push_back(&ground_dirt_model);
    }
    /*for(unsigned int y  = 0 ; y < map_size_tiles_.y ; ++y){
        for(unsigned int  x = 0 ; x < map_size_tiles_.x ; ++x){
            ground_map_.emplace_back(Ground(sf::Vector2f(x * g_tile_size.x,
                                            y * g_tile_size.y)));
        }
    }*/
}

GameData::~GameData()
{
    //dtor
}


void
GameData::ReceiveInput(std::array<bool, kInput_Count> keys_down,
                       std::array<bool, kInput_Count> last_keys_down)
{

}

void
GameData::PlayerShoots(const float angle_to_mouse){
    player_.Shoot(projectiles_, angle_to_mouse);
}


void
GameData::Update(){
    if(game_state_ == kGameState_Playing){
        for(auto o = projectiles_.begin() ; o != projectiles_.end() ; ){
            if(o->Update()){
                o = projectiles_.erase(o);
            }
            else{
                ++o;
            }
        }
    }
}

void
GameData::CreateMapGridObject(const eObjectType type,
                       const sf::Vector2u& tile_position){
    /*int vector_position = tile_position.x + tile_position.y * map_size_tiles_.y;
    sf::Vector2f position_in_pixels = ConvertTilePositionToPixels(tile_position);
    switch(type){
    case kOBject_Ground_Grass:
        ground_map_[vector_position] = &ground_grass_model;
        break;
    }*/
}


