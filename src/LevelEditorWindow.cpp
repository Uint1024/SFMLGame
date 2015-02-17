/* 
 * File:   LevelEditorWindow.cpp
 * Author: John
 * 
 * Created on 16 février 2015, 01:52
 */

#include "LevelEditorWindow.h"
#include "Engine.h"
#include "InputManager.h"

LevelEditorWindow::LevelEditorWindow(const sf::Vector2f& position) :
displayed_(true),
GUI(position, sf::Vector2f{200, 200}){
}

LevelEditorWindow::~LevelEditorWindow() {
}

void 
LevelEditorWindow::Render(Engine& engine) {
    sf::RectangleShape rect(bbox_.GetSize());
    
    /*sf::Vector2f cam_center = engine.GetCamera().getCenter();
    sf::Vector2f cam_size = engine.GetCamera().getSize();
    sf::Vector2f bbox_real_pos = 
                            { cam_center.x - cam_size.x/2.0f + bbox_.GetLeft(),
                              cam_center.y - cam_size.y/2.0f + bbox_.GetUp()};*/
    
    rect.setFillColor(sf::Color{50, 50, 50});
   rect.setPosition(bbox_.GetPosition());
    engine.GetWindow().draw(rect);
}

void 
LevelEditorWindow::Update(Engine& engine, InputManager& input_manager) {
    /*if(bbox_.CheckPointIntersecti(input_manager.GetMousePositionWindow()) &&
       input_manager.GetKeysDown()[kInput_Shoot]){
        clicked_on_ = true; 
    }
    else{
        clicked_on_ = false;
    }
    
    if(clicked_on_){
        bbox_.SetPosition(
            sf::Vector2f{
                static_cast<float>(input_manager.GetMousePositionWindow().x),
                static_cast<float>(input_manager.GetMousePositionWindow().y)});
    }*/
}


