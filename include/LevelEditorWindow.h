/* 
 * File:   LevelEditorWindow.h
 * Author: John
 *
 * Created on 16 février 2015, 01:52
 */

#ifndef LEVELEDITORWINDOW_H
#define	LEVELEDITORWINDOW_H
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include "Globals.h"
#include "Bbox.h"
#include "GameObject.h"
#include "GUI.h"

class Engine;
class LevelEditorWindow : public GUI{
public:
    LevelEditorWindow(const sf::Vector2f& position);
    virtual ~LevelEditorWindow();
    void Render(Engine& engine) override;

    virtual void Update(Engine& engine, InputManager& input_manager) override;

private:
    bool displayed_;
    bool clicked_on_;

};

#endif	/* LEVELEDITORWINDOW_H */

