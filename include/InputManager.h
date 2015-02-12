#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "InputEnum.h"
#include "Globals.h"
#include "Player.h"

class Engine;
class GameData;

class InputManager
{
    public:
        InputManager(Engine* engine, GameData* game_data);
        ~InputManager();
        int PollEvents();
        void EditLevel();
        void Play();
    protected:
    private:
        Engine* engine_;
        GameData* game_data_;
        Player& player_;
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
