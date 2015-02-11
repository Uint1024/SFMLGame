#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <list>
#include <array>
#include <SFML/System.hpp>
#include "InputEnum.h"
#include "Player.h"
#include "Projectile.h"

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

    protected:
    private:

        sf::Vector2u map_size_tiles_;
        sf::Vector2u tile_size_;
        Engine& engine_;
        sf::Vector2u map_size_pixels_;
        std::list<Projectile> projectiles_;
        Player player_;

};

#endif // GAMEDATA_H
