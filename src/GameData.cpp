#include <iostream>

#include "GameData.h"
#include "Engine.h"
#include "InputManager.h"
#include "PhysicsSolid.h"
#include "ControlsPlayer.h"
#include "GraphicsVisible.h"
#include "ControlsLevelEditor.h"
#include "ControlsComponent.h"
#include "HealthComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "ControlsAI.h"
#include "DoorComponent.h"
#include "InventoryComponent.h"


inline sf::Vector2f
ConvertTilePositionToPixels(const sf::Vector2u& tile_position){
    return {tile_position.x * g_tile_size.x,
            tile_position.y + g_tile_size.y};
}

GameData::GameData(Engine& engine, InputManager& input_manager) :
    map_size_tiles_(100,100),
    tile_size_(64,64),
    engine_(engine),
    input_manager_(input_manager),
    game_state_(kGameState_Editor),
    ground_dirt_model(kTexture_Ground_Dirt),
    ground_grass_model(kTexture_Ground_Grass),
    player_(GameObject(sf::Vector2f{static_cast<float>(engine.GetWindowSize().x/2),
                                    static_cast<float>(engine.GetWindowSize().y/2)},
                       sf::Vector2f{40,40},
                       new PhysicsSolid(),
                       new GraphicsVisible(kTexture_Ground_Cement),
                       nullptr,
                       new ControlsPlayer(input_manager),
                       new HealthComponent(), new InventoryComponent()))
{
    sf::Vector2u window_size = engine_.GetWindow().getSize();

    map_size_pixels_ = sf::Vector2u(map_size_tiles_.x * tile_size_.x,
                                    map_size_tiles_.y * tile_size_.y);

    total_tiles_ = map_size_tiles_.x * map_size_tiles_.y;


    for(int i = 0 ; i < total_tiles_ ; ++i){
        occupied_solid_map_.push_back(false);
        ground_map_.push_back(&ground_dirt_model);
    }
    
    
    
    wall_map_.emplace_back(GameObject(
    sf::Vector2f{500,500},
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Wall_Black),
                            nullptr));

}

GameData::~GameData()
{
    //dtor
}

void
GameData::PlayerShoots(const float angle_to_mouse){
    //player_.Shoot(projectiles_, angle_to_mouse);
}


int
GameData::Update(){
    int quit = input_manager_.PollEvents(engine_, *this);

    engine_.Clear();

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f{g_tile_size.x,
                  g_tile_size.y});

    if(g_game_state){
        //engine_
    }
    engine_.Render(*this);

    for(auto o = projectiles_.begin() ; o != projectiles_.end() ; ){
        if(!o->Update(engine_, *this)){
            o = projectiles_.erase(o);
        }
        else{
            ++o;
        }
    }


    for(auto &o : wall_map_){
        o.Update(engine_, *this);
        
    }
    for(auto &o : doors_map_){
        o.Update(engine_, *this);
    }
    
    
    for(auto o = npcs_.begin() ; o != npcs_.end() ; ){
        if(!o->Update(engine_, *this)){
            o = npcs_.erase(o);
        }
        else{
            ++o;
        }    
    }

    player_.Update(engine_, *this);
    if(g_game_state == kGameState_Editor){
        player_.GetControls()->Update(&player_, engine_, *this);
    }
    
    engine_.Display();
    return quit;
}

void
GameData::CreateObjectAtMousePosition(const eObjectType type){
    int vector_position = input_manager_.GetMouseVectorMapPosition(map_size_tiles_);
    std::cout << vector_position << std::endl;
    sf::Vector2f grid_pos_pixels{
        static_cast<float>(input_manager_.GetMouseTilePositionInPixels().x),
        static_cast<float>(input_manager_.GetMouseTilePositionInPixels().y)};

    if(type == kObject_Ground){
        ground_map_[vector_position] = &ground_grass_model;
    }else if(type == kObject_Wall && 
        !occupied_solid_map_[vector_position]){
                wall_map_.emplace_back(GameObject(
                            grid_pos_pixels,
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Wall_Black),
                            nullptr));  
        occupied_solid_map_[vector_position] = true;
    }else if (type == kObject_Door &&
        !occupied_solid_map_[vector_position]) {
        doors_map_.emplace_back(GameObject(
                            grid_pos_pixels,
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Door_Grey),
                            new DoorComponent()                            
                            ));
                                
                                          
        occupied_solid_map_[vector_position] = true;
    } else if(type == kObject_Guard) {
        npcs_.emplace_back(GameObject(
                input_manager_.GetMousePositionInWorldInPixels(),
                sf::Vector2f{40,40},
                new PhysicsSolid(),
                new GraphicsVisible(kTexture_Guard),
                nullptr,
                new ControlsAI(),
                new HealthComponent(),
                new InventoryComponent()));
    }   
}

void
GameData::ToggleLevelEditorMode(){
    if(g_game_state == kGameState_Editor){
        g_game_state = kGameState_Playing;
        player_.SetControls(new ControlsPlayer(input_manager_));
    } else {
        g_game_state = kGameState_Editor;
        player_.SetControls(new ControlsLevelEditor(input_manager_));
    }
}



