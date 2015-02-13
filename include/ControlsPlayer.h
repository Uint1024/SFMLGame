#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H
#include <SFML/System/Vector2.hpp>
#include <ControlsComponent.h>

class InputManager;
class GameObject;
class Engine;
class GameData;
class ControlsPlayer : public ControlsComponent
{
    public:
        ControlsPlayer(InputManager& input_manager);
        virtual ~ControlsPlayer();
        virtual void Update(GameObject* object, Engine& engine,
                            GameData& game_data) override;
    protected:
    private:
        const float speed_ = 10;
        InputManager& input_manager_;
};

#endif // PLAYERCONTROLS_H
