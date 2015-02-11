#include "GameData.h"
#include "Engine.h"

GameData::GameData(Engine& engine) :
    map_size_tiles_(100,100),
    tile_size_(64,64),
    engine_(engine)
{
    sf::Vector2u window_size = engine_.GetWindow().getSize();
    player_ = Player(sf::Vector2f{   static_cast<float>(window_size.x/2),
                            static_cast<float>(window_size.y/2)});

    map_size_pixels_ = sf::Vector2u(map_size_tiles_.x * tile_size_.x,
                                    map_size_tiles_.y * tile_size_.y);
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
    for(auto &o : projectiles_){
        o.Update();
    }
}
