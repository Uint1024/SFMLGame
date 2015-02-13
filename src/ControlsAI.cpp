/* 
 * File:   ControlsAI.cpp
 * Author: John
 * 
 * Created on 13 février 2015, 04:24
 */

#include "ControlsAI.h"
#include "GameObject.h"
#include "GameData.h"


ControlsAI::ControlsAI(){
}

ControlsAI::ControlsAI(const ControlsAI& orig) {
}

ControlsAI::~ControlsAI() {
}

void ControlsAI::Update(GameObject* object, 
        Engine& engine, GameData& game_data) {
  object->Move(movement_);
  
  movement_ = sf::Vector2f{0,0};
  GameObject& player = game_data.GetPlayer();
  
  if(player.getPosition().x > object->getPosition().x){
    movement_.x += 5;
  }
  else{
    movement_.x -= 5;
  }
  
  if(player.getPosition().y > object->getPosition().y){
    movement_.y += 5;
  }
  else {
    movement_.y -= 5;
  }
}
