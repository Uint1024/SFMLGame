/* 
 * File:   Button.cpp
 * Author: John
 * 
 * Created on 17 février 2015, 00:11
 */

#include "Button.h"
#include "Engine.h"
#include "InputManager.h"
#include "LevelEditorWindow.h"

//we initialize the bbox at 0 because it will be calculated from the font's size
//then the parent has to move the buttons to the correct position
Button::Button(const int type, const int subtype, const char* label,
               GUI* parent, Engine& engine) :
              
GUI(sf::Vector2f{0.0f,0.0f}, sf::Vector2f{0.0f, 0.0f}),
label_(label, engine.GetFont(), 20),
parent_(parent),
type_(type),
subtype_(subtype){
    bbox_.SetHeight(label_.getGlobalBounds().height);
    bbox_.SetWidth(label_.getGlobalBounds().width);
    label_.setColor(sf::Color(200, 0, 0));
    label_.setStyle(sf::Text::Bold);
}


Button::~Button() {
}

void 
Button::Update(Engine& engine, InputManager& input_manager){
    if(bbox_.CheckPointIntersecti(input_manager.GetMousePositionWindow()) &&
       input_manager.GetKeysDown()[kInput_Shoot]){
        parent_->ClickedOnChild(type_, subtype_);
    }
    
    
    Render(engine);
}

void 
Button::Render(Engine& engine){
    label_.setPosition(bbox_.GetPosition());
    
    engine.GetWindow().draw(label_);
}

void 
Button::PlaceInParent(GUI* parent, const sf::Vector2f& margin) {
    bbox_.MoveTo(sf::Vector2f{margin.x + parent->GetBbox().GetLeft(),
                              margin.y + parent->GetBbox().GetUp()});
    
}


