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
#include "Engine.h"

ControlsAI::ControlsAI() :
ControlsComponent(true),
path_(0),
next_node_(0),
previous_node_(-1),
go_in_reverse_(false),
angry_(false),
fov_(PI),
havent_seen_player_for_(0){
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
        movement_ = {static_cast<float>(cos(angle_to_next_node) 
                        * speed_ * g_delta_time), 
                  static_cast<float>(sin(angle_to_next_node)  
                        * speed_ * g_delta_time)};
    }
    else{
        movement_ = {
            static_cast<float>(cos(angle_to_player) * speed_ * g_delta_time), 
            static_cast<float>(sin(angle_to_player)  * speed_ * g_delta_time)};
        
    }
    
    
    //TODO : raytracing
    sf::Vector2f vector_to_player { player.getPosition().x - 
                                            object->getPosition().x,
                                        player.getPosition().y - 
                                            object->getPosition().y};
    //normalize vertors
   float vector_length = PythagorasDistance(vector_to_player);
   vector_to_player = {vector_to_player.x / vector_length, vector_to_player.y / vector_length};
   vector_length = PythagorasDistance(movement_);
   sf::Vector2f normalized_movement = {movement_.x / vector_length, movement_.y / vector_length};

   //dot product, This gives the cosine of the angle 
   //thanks Google
   float dot_product = normalized_movement.x * vector_to_player.x +
                       normalized_movement.y * vector_to_player.y;

   auto& walls_map = game_data.GetWalls();
   if(dot_product > 0.0f  && dot_product < 1.0f ){
       angry_ = true;
       sf::Vector2f raycasted = object->getPosition();
       float distance_to_player = DistanceBetween2Points(
                                       object->getPosition(),
                                       player.getPosition());
       float distance_raycast = 0.0f;
 //std::cout << distance_raycast << " " << distance_to_player << std::endl;
       while(distance_raycast < distance_to_player){
           sf::Vector2f raycast_movement{
                   static_cast<float>(cos(angle_to_player) * 60.0f),
                   static_cast<float>(sin(angle_to_player) * 60.0f)};
           raycasted.x += raycast_movement.x;
           raycasted.y += raycast_movement.y;
           distance_raycast += PythagorasDistance(raycast_movement);
           for(auto &wall : walls_map){
               if(wall.GetBbox().CheckPointIntersect(raycasted)){
                   std::cout << "boom" << std::endl;
                   angry_ = false;
                   distance_raycast = distance_to_player;
                   break;
               }
           }
       }
       
       sf::Vertex vertices[2] = { sf::Vertex(object->getPosition()), 
                                  sf::Vertex(raycasted)};
       engine.GetWindow().draw(vertices, 2, sf::Lines);
   }
        
    
    
    for(auto &o : objects_collisions_list_){
        if(o){
          o->ReceiveMessage(Message{object, kMsg_Use, 0, 0});
        }
    }
    objects_collisions_list_.clear();
}
