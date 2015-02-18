/* 
 * File:   Button.h
 * Author: John
 *
 * Created on 17 février 2015, 00:11
 */

#ifndef BUTTON_H
#define	BUTTON_H
#include "GUI.h"
#include <string>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Bbox.h"



class InputManager;
class Engine;
class LevelEditorWindow;
class Button : public GUI{
public:
    Button(const int type, const int subtype, const char* label,
            GUI* parent, Engine& engine);
    virtual ~Button();

    void Update(Engine& engine, InputManager& input_manager);

    virtual void ClickedOnChild(const int type, const int subtype){
        //can't have children, do nothing
    }

    void Render(Engine& engine);
    void PlaceInParent(GUI* parent, const sf::Vector2f& margin);
    const sf::Text& GetLabel() const{
        return label_;
    }
    
    bool SetSelected(const bool selected) {
        selected_ = selected;
    }
    bool IsSelected() const{
        return selected_;
    }
private:
    bool selected_;
    sf::Text label_;
    GUI* parent_;
    int type_;
    int subtype_;
};

#endif	/* BUTTON_H */

