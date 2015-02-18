#include <iostream>
#include <fstream>
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
#include "ArrowMachinegun.h"
#include "UsableChest.h"
#include "WeaponFireStaff.h"


inline sf::Vector2f
ConvertTilePositionToPixels(const sf::Vector2u& tile_position){
    return {tile_position.x * g_tile_size.x,
            tile_position.y + g_tile_size.y};
}

GameData::GameData(Engine& engine, InputManager& input_manager) :
    map_size_tiles_(30,20),
    tile_size_(64,64),
    engine_(engine),
    input_manager_(input_manager),
    game_state_(kGameState_Editor),
    ground_dirt_model(kTexture_Ground_Dirt),
    ground_grass_model(kTexture_Ground_Grass),
    level_editor_window_{sf::Vector2f{10, 10}, engine}
{
                        
    //comment créer des paths _simples_ pour l'ia
    
    //vector de listes de positions
    //chaque ennemi est attribué un ID de path et le suit du début à la fin
    //
                           

    map_size_pixels_ = sf::Vector2u(map_size_tiles_.x * tile_size_.x,
                                    map_size_tiles_.y * tile_size_.y);

    total_tiles_ = map_size_tiles_.x * map_size_tiles_.y;


    for(int i = 0 ; i < total_tiles_ ; ++i){
        //occupied_solid_map_.push_back(false);
        ground_map_.push_back(&ground_dirt_model);
    }
    
    //Reading map from text file
    char ch;
    std::ifstream stream;
    stream.open("map1.txt", std::ios::in);
    
    int x = 0;
    int y = 0;
    while(!stream.eof()){
        stream.get(ch);
        
        if(ch == 'W'){
            wall_map_.emplace_back(GameObject(
                            sf::Vector2f{x * g_tile_size.x, y * g_tile_size.y},
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Wall_Black),
                            nullptr));
        }
        else if(ch == 'D'){
            wall_map_.emplace_back(GameObject(
                            sf::Vector2f{x * g_tile_size.x, y * g_tile_size.y},
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Door_Grey),
                            new DoorComponent()                            
                            ));
        }
        else if(ch == 'P'){
            auto player_position = sf::Vector2f{x * g_tile_size.x,
                                    y * g_tile_size.y};

            player_ = GameObject(player_position,
                       sf::Vector2f{40,40},
                       new PhysicsSolid(),
                       new GraphicsVisible(kTexture_Ground_BlueCarpet),
                       nullptr,
                       new ControlsPlayer(input_manager),
                       new HealthComponent(100), new InventoryComponent());
            engine.CenterCameraOnPlayer(player_position);
            player_.GetInventory()->AddWeapon(new ArrowMachinegun());   
        }
        if(ch == '\n'){
            ++y;
            x = 0;
        }
        else{
            ++x;
        }
    }
    
    stream.close();
    
    stream.open("path0.txt", std::ios::in);
    
    x = 0;
    y = 0;
    
    ai_paths_.push_back(std::vector<sf::Vector2f>());
    int nb_of_nodes = 0;
    if(stream.is_open()){
        stream.get(ch);
        if(ch >= '0' && ch <= '9'){
            nb_of_nodes = std::stoi(std::string(&ch));
        }     
    }
    ai_paths_[0].resize(nb_of_nodes);
    while(!stream.eof()){
        stream.get(ch);

        if(ch >= '0' && ch <= '9'){
            ai_paths_[0][std::stoi(std::string(&ch))] = sf::Vector2f{x * g_tile_size.x, 
                                                    y * g_tile_size.y};
        }
        if(ch == '\n'){
            ++y;
            x = 0;
        }
        else{
            ++x;
        }
    }
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
    engine_.Clear();

    engine_.Render(*this);
    
    int quit = input_manager_.PollEvents(engine_, *this);

    for(auto &o : wall_map_){
        o.Update(engine_, *this);
        
    }
    for(auto &o : doors_map_){
        o.Update(engine_, *this);
    }
    
    for(auto o = projectiles_.begin() ; o != projectiles_.end() ; ){
        if(!o->Update(engine_, *this)){
            o = projectiles_.erase(o);
        }
        else{
            ++o;
        }
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
    
    engine_.GetWindow().setView(engine_.GetWindow().getDefaultView());
    level_editor_window_.Update(engine_, input_manager_);
    
    engine_.Display();
    return quit;
}

void
GameData::CreateObjectAtMousePosition(const eObjectType type){
    int vector_position = input_manager_.GetMouseVectorMapPosition(map_size_tiles_);
    sf::Vector2f grid_pos_pixels{
        static_cast<float>(input_manager_.GetMouseTilePositionInPixels().x),
        static_cast<float>(input_manager_.GetMouseTilePositionInPixels().y)};
    
    if(type == kObject_Wall || type == kObject_Door || type == kObject_Chest){
        if(std::find_if(wall_map_.begin(), wall_map_.end(),
                        [&grid_pos_pixels](GameObject &go){ 
                            return (go.getPosition().x == grid_pos_pixels.x &&
                            go.getPosition().y == grid_pos_pixels.y);
                        }) != wall_map_.end()){
            return;
        }
    }
    if(type == kObject_Ground){
        ground_map_[vector_position] = &ground_grass_model;
        std::cout << "vector position = " << vector_position << std::endl;
    }else if(type == kObject_Wall){
                wall_map_.emplace_back(GameObject(
                            grid_pos_pixels,
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Wall_Black),
                            nullptr));  
        //occupied_solid_map_[vector_position] = true;
    }else if (type == kObject_Door) {
        wall_map_.emplace_back(GameObject(
                            grid_pos_pixels,
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Door_Grey),
                            new DoorComponent()                            
                            ));
                                
                                          
        //occupied_solid_map_[vector_position] = true;
    }else if (type == kObject_Chest) {
        wall_map_.emplace_back(GameObject(
                            grid_pos_pixels,
                            g_tile_size,
                            new PhysicsSolid(),
                            new GraphicsVisible(kTexture_Guard),
                            new UsableChest(),
                            nullptr,
                            nullptr,
                            new InventoryComponent(new ArrowMachinegun())
                            ));
                                
                                          
        //occupied_solid_map_[vector_position] = true;
    } else if(type == kObject_Guard) {
        npcs_.emplace_back(GameObject(
                input_manager_.GetMousePositionInWorldInPixels(),
                sf::Vector2f{40,40},
                new PhysicsSolid(),
                new GraphicsVisible(kTexture_Guard),
                nullptr,
                new ControlsAI(),
                new HealthComponent(40),
                new InventoryComponent()));
    }   
}

void
GameData::ToggleLevelEditorMode(){
    if(g_game_state == kGameState_Editor){
        g_game_state = kGameState_Playing;
        level_editor_window_.SetDisplayed(false);
        player_.SetControls(new ControlsPlayer(input_manager_));
    } else {
        g_game_state = kGameState_Editor;
        level_editor_window_.SetDisplayed(true);
        player_.SetControls(new ControlsLevelEditor(input_manager_));
    }
}



