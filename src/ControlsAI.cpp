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
ControlsComponent(true),
path_(0),
next_node_(0),
previous_node_(-1),
go_in_reverse_(false),
angry_(false),
fov_(PI){
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
    
    //need to calculate field of view
    //1) is player in 90° angle in front of AI
    //2) is he behind a wall (raycast))
    

    float angle_to_next_node = 
                        AngleBetween2Points(object->getPosition(),
                                            game_data.GetAiPaths()[path_][next_node_]);

    if((abs(object->getPosition().x - game_data.GetAiPaths()[path_][next_node_].x) < 10) &&
       (abs(object->getPosition().y - game_data.GetAiPaths()[path_][next_node_].y) < 10)){
        previous_node_ = next_node_;
        next_node_ = go_in_reverse_ ? next_node_ - 1 :
                                      next_node_ + 1;
        if(next_node_ >= game_data.GetAiPaths()[path_].size() - 1){
            go_in_reverse_ = true;
        }
        if(next_node_ == - 1){
            go_in_reverse_ = false;
            next_node_ = 0;
        }
    }

    if(!angry_){
        movement_ = {static_cast<float>(cos(angle_to_next_node) * speed_ * g_delta_time), 
                  static_cast<float>(sin(angle_to_next_node)  * speed_ * g_delta_time)};
        
        sf::Vector2f vector_to_player {player.getPosition().x - object->getPosition().x,
                                    player.getPosition().y - object->getPosition().y};
         //normalize vertors
        float vector_length = PythagorasDistance(vector_to_player);
        vector_to_player = {vector_to_player.x / vector_length, vector_to_player.y / vector_length};
        vector_length = PythagorasDistance(movement_);
        sf::Vector2f normalized_movement = {movement_.x / vector_length, movement_.y / vector_length};
    
        //dot product, This gives the cosine of the angle 
        //thanks Google
        float dot_product = normalized_movement.x * vector_to_player.x +
                            normalized_movement.y * vector_to_player.y;
        if(dot_product > 0.35  && dot_product < 0.65 ){
            angry_ = true;
        }
    }
    else{
        movement_ = {static_cast<float>(cos(angle_to_player) * speed_ * g_delta_time), 
                  static_cast<float>(sin(angle_to_player)  * speed_ * g_delta_time)};
    }
    
    for(auto &o : objects_collisions_list_){
        if(o){
          o->ReceiveMessage(Message{object, kMsg_Use, 0, 0});
        }
    }
    objects_collisions_list_.clear();
}
