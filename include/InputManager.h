#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "InputEnum.h"

class Engine;
class GameData;

class InputManager
{
    public:
        InputManager(Engine* engine, GameData* game_data);
        ~InputManager();
        int PollEvents();
    protected:
    private:
        Engine* engine_;
        GameData* game_data_;
        std::array<sf::Keyboard::Key, kInput_Count> keyboard_mapping_;
        std::array<sf::Mouse::Button, kInput_Count> mouse_mapping_;
        std::array<bool, kInput_Count> keys_down_;
        std::array<bool, kInput_Count> last_keys_down_;

};

#endif // INPUTMANAGER_H
