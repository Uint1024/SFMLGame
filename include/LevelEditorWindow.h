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
#include <memory>
#include "Button.h"
#include "Globals.h"
#include "Bbox.h"
#include "GameObject.h"
#include "GUI.h"

class Engine;
class LevelEditorWindow : public GUI{
public:
    LevelEditorWindow(const sf::Vector2f& position, Engine& engine);
    virtual ~LevelEditorWindow();
    void Render(Engine& engine) override;

    void Update(Engine& engine, InputManager& input_manager) override;
    void ClickedOnChild(const int type, const int subtype) override{
        selected_object_type_ =     static_cast<eObjectType>(type);
        selected_object_texture_ =  static_cast<eTexture>(subtype);
    }
    
    bool IsClickedOn() const {
        return clicked_on_;
    }

    bool IsDisplayed() const {
        return displayed_;
    }
    
    void SetClickedOn(bool clicked_on) {
        this->clicked_on_ = clicked_on_;
    }

    void SetDisplayed(bool displayed) {
        this->displayed_ = displayed;
    }
    
    bool IsHover() const {
        return hover_;
    }
    
    void Move(const sf::Vector2f& movement) override;
    
    eObjectType GetSelectedObjectType() const{
        return selected_object_type_;
    }
    
private:
    bool displayed_;
    bool hover_;
    bool clicked_on_;
    std::array<std::unique_ptr<Button>, kObject_Count> buttons_;
    eObjectType selected_object_type_;
    eTexture selected_object_texture_;

};

#endif	/* LEVELEDITORWINDOW_H */

