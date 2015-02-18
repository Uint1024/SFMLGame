/* 
 * File:   LevelEditorWindow.cpp
 * Author: John
 * 
 * Created on 16 février 2015, 01:52
 */

#include "LevelEditorWindow.h"
#include "Engine.h"
#include "InputManager.h"

LevelEditorWindow::LevelEditorWindow(const sf::Vector2f& position, 
                                     Engine& engine) :
displayed_(false),
hover_(false),
clicked_on_(false),
buttons_{nullptr},
GUI(position, sf::Vector2f{200, 200}){
    
    buttons_[kObject_Wall] = std::make_unique<Button>(kObject_Wall, 0, "Wall", 
                              this, engine);
    buttons_[kObject_Guard] =  std::make_unique<Button>(kObject_Guard, 0, 
                            "Guard", this, engine); 
    buttons_[kObject_Chest] =  std::make_unique<Button>(kObject_Chest, 0, 
                            "Chest", this, engine); 
    buttons_[kObject_Ground] =  std::make_unique<Button>(kObject_Ground, 0, 
                            "Ground", this, engine); 

    
                              
     
}

LevelEditorWindow::~LevelEditorWindow() {
}

void 
LevelEditorWindow::Render(Engine& engine) {
    if(displayed_){
        sf::RectangleShape rect(bbox_.GetSize());

        rect.setFillColor(sf::Color{50, 50, 50});
        rect.setPosition(bbox_.GetPosition());
        engine.GetWindow().draw(rect);
    }
}

void 
LevelEditorWindow::Update(Engine& engine, InputManager& input_manager) {
    for(int i = 0 ; i < buttons_.size() ; ++i){
        if(buttons_[i]){
            int button_height = buttons_[i]->GetLabel().getGlobalBounds().height;
            buttons_[i]->PlaceInParent(this, 
                                       sf::Vector2f(10, 10 + button_height * i));
            buttons_[i]->Update(engine, input_manager);
        }
    }
    
    if(displayed_){
        if(bbox_.CheckPointIntersect(
                    sf::Vector2f(input_manager.GetMousePositionWindow().x,
                                 input_manager.GetMousePositionWindow().y))){
            hover_ = true; 
        }
        else{
            hover_ = false;
            clicked_on_ = false;
        }
        
        if(hover_ && input_manager.GetKeysDown()[kInput_Shoot]){
            clicked_on_ = true;
        }

        if(clicked_on_ && input_manager.GetKeysDown()[kInput_Shoot]){
            Move(input_manager.GetMouseMovement());
        }
        
        Render(engine);
        
        for(auto &button : buttons_){
            if(button){
                button->Update(engine, input_manager);
            }
        }
    }
}

void 
LevelEditorWindow::Move(const sf::Vector2f& movement) {
    bbox_.Move(movement);
    for(int i = 0 ; i < buttons_.size() ; ++i){
        if(buttons_[i]){
            int button_height = buttons_[i]->GetLabel().getGlobalBounds().height;
            buttons_[i]->PlaceInParent(this, 
                                       sf::Vector2f(10, 10 + button_height * i));
        }
    }
}
