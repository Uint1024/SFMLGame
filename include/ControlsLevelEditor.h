#ifndef CONTROLSLEVELEDITOR_H
#define CONTROLSLEVELEDITOR_H
#include "ControlsComponent.h"
#include "Globals.h"

class InputManager;
class GameObject;
class Engine;
class GameData;
class ControlsLevelEditor : public ControlsComponent
{
    public:
        ControlsLevelEditor(InputManager& input_manager);
        virtual ~ControlsLevelEditor();
        virtual void Update(GameObject* object, Engine& engine,
                            GameData& game_data) override;
    protected:
    private:
        const float speed_ = 36;
        eObjectType le_selected_object_;

};
#endif // CONTROLSLEVELEDITOR_H
