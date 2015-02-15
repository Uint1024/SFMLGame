/* 
 * File:   ControlsAI.cpp
 * Author: John
 * 
 * Created on 13 février 2015, 04:24
 */

#include <cmath>
#include "ControlsAI.h"
#include "GameObject.h"
#include "GameData.h"
#include "Maths.h"

ControlsAI::ControlsAI() :
ControlsComponent(true){
}

ControlsAI::~ControlsAI() {
}

void ControlsAI::Update(GameObject* object, 
        Engine& engine, GameData& game_data) {
    object->Move(movement_);

    movement_ = sf::Vector2f{0,0};
    GameObject& player = game_data.GetPlayer();

    float angle_to_player = AngleBetween2Points(object->getPosition(),
                                              player.getPosition());

    movement_ = {static_cast<float>(cos(angle_to_player)), 
                  static_cast<float>(sin(angle_to_player))};

    for(auto &o : objects_collisions_list_){
        if(o){
          o->ReceiveMessage(Message{object, kMsg_Use, 0, 0});
        }
    }
    objects_collisions_list_.clear();
}
