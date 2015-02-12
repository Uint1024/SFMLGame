#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <list>
#include <array>
#include <SFML/System.hpp>
#include "InputEnum.h"
#include "Player.h"
#include "Projectile.h"
#include "Ground.h"
#include "Globals.h"


class Wall;
class Engine;
class GameData
{
    public:
        GameData(Engine& engine);
        ~GameData();
        void ReceiveInput(std::array<bool, kInput_Count> keys_down,
                          std::array<bool, kInput_Count> last_keys_down);
        void PlayerShoots(const float angle_to_mouse);
        void Update();
        void CreateMapGridObject(const eObjectType type,
                                 const sf::Vector2u& tile_position);



        inline void ToggleLevelEditorMode(){
            game_state_ = kGameState_Editor?    kGameState_Playing :
                                                kGameState_Editor;
        }

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

        inline Player& GetPlayer(){
            return player_;
        }

        inline std::list<Projectile>& GetProjectiles(){
            return projectiles_;
        }
        inline std::vector<Wall*>& GetWalls(){
            return wall_map_;
        }
        inline std::vector<Ground*>& GetGround(){
            return ground_map_;
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
        sf::Vector2u map_size_pixels_;
        std::list<Projectile> projectiles_;
        std::vector<Wall*> wall_map_;

        //the same ground type will point to the same object
        std::vector<Ground*> ground_map_;
        Player player_;
        int total_tiles_;
        eGameState game_state_;

        Ground ground_grass_model;
        Ground ground_dirt_model;

};

#endif // GAMEDATA_H
