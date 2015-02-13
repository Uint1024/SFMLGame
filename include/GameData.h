#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <iostream>
#include <list>
#include <array>
#include <SFML/System.hpp>
#include "InputEnum.h"
#include "Ground.h"
#include "Globals.h"
#include "GameObject.h"


class Engine;
class InputManager;
class GameData
{
    public:
        GameData(Engine& engine, InputManager& input_manager);
        ~GameData();
        void PlayerShoots(const float angle_to_mouse);
        int Update();
        void CreateObjectAtMousePosition(const eObjectType type);

        void ToggleLevelEditorMode();

        //Accessors:
        inline sf::Vector2u GetMapSizeInTiles() const{
            return map_size_tiles_;
        }

        inline sf::Vector2u GetMapSizeInPixels() const{
            return map_size_pixels_;
        }

        inline sf::Vector2u GetTileSize() const{
            return tile_size_;
        }

        inline GameObject& GetPlayer(){
            return player_;
        }

        inline std::list<GameObject>& GetProjectiles(){
            return projectiles_;
        }
        inline std::vector<GameObject*>& GetWalls(){
            return wall_map_;
        }
        inline std::vector<Ground*>& GetGround(){
            return ground_map_;
        }
        inline auto& GetNpcs(){
            return npcs_;
        }
       

        inline int GetTotalTiles() const {
            return total_tiles_;
        }

        inline eGameState GetGameState() const {
            return game_state_;
        }

    protected:
    private:

        sf::Vector2u map_size_tiles_;
        sf::Vector2u tile_size_;
        Engine& engine_;
        InputManager& input_manager_;
        sf::Vector2u map_size_pixels_;
        std::list<GameObject> npcs_;
        std::list<GameObject> projectiles_;
        std::vector<GameObject*> wall_map_;

        //the same ground type will point to the same object
        std::vector<Ground*> ground_map_;
        GameObject player_;
        int total_tiles_;
        eGameState game_state_;

        Ground ground_grass_model;
        Ground ground_dirt_model;

};

#endif // GAMEDATA_H
