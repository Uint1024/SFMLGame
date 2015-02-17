#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "InputEnum.h"
#include "Globals.h"
class Engine;
class GameData;

class InputManager
{
    public:
        InputManager();
        ~InputManager();
        int PollEvents(Engine& engine, GameData& game_data);
        void EditLevel(GameData& game_data);
        void Play(GameData& game_data);
        float GetAngleToMouse(const sf::Vector2f& object_pos);

        //Accessors:

        const std::array<bool, kInput_Count>& GetKeysDown() const{
            return keys_down_;
        }

        const std::array<bool, kInput_Count>& GetLastKeysDown() const {
            return last_keys_down_;
        }
        
        const sf::Vector2i& GetMousePositionWindow() const {
            return mouse_position_window_;
        }

        const sf::Vector2f& GetMousePositionInWorldInPixels() const{
            return mouse_position_world_;
        }

        const sf::Vector2u& GetMouseTilePositionInTiles() const{
            return mouse_tile_position_in_tiles_;
        }

        const sf::Vector2u& GetMouseTilePositionInPixels() const{
            return mouse_tile_position_in_pixels_;
        }

        int GetMouseVectorMapPosition(const sf::Vector2u map_size) const{
            return mouse_tile_position_in_tiles_.x +
                    mouse_tile_position_in_tiles_.y *
                    map_size.y;
        }



    protected:
    private:
        sf::Vector2i mouse_position_window_;
        sf::Vector2f mouse_position_world_;
        sf::Vector2u mouse_tile_position_in_tiles_;
        sf::Vector2u mouse_tile_position_in_pixels_;
        std::array<sf::Keyboard::Key, kInput_Count> keyboard_mapping_;
        std::array<sf::Mouse::Button, kInput_Count> mouse_mapping_;
        std::array<bool, kInput_Count> keys_down_;
        std::array<bool, kInput_Count> last_keys_down_;
        eObjectType le_selected_object_;
};

#endif // INPUTMANAGER_H
