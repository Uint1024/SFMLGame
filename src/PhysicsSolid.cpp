#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

#include "GameObject.h"
#include "GameData.h"
#include "PhysicsSolid.h"
#include "Bbox.h"
#include "UseComponent.h"
#include "Globals.h"

PhysicsSolid::PhysicsSolid()
{
    //ctor
}

PhysicsSolid::~PhysicsSolid()
{
    //dtor
}

bool
PhysicsSolid::Update(GameObject* object,
                     GameData& game_data,
                     ControlsComponent* controls,
                     Engine& engine)
{
    if(controls){
        sf::Vector2f movement = controls->GetMovement();
        auto& walls_map = game_data.GetWalls();
        auto& npcs_list = game_data.GetNpcs();
        
        //future bbox if the current movement are applied 
        //(ie if there's no collision)
        Bbox future_bbox = object->GetBbox();
        future_bbox.Move(movement);
        
        std::array<Bbox*, kDirection_Count> collisions_in_4_directions{nullptr};
        std::array<int, kDirection_Count> nb_of_collisions_in_4_directions{0};
        bool collision = false;
        bool intersect = false;
        
        
        for(auto &o : walls_map){
            intersect = false;
            if(o.GetPhysics()){
                
                eDirection direction_of_collision = kDirection_None;

                //intersect if the 2 bbox rectangles are superimposed
                if(o.GetBbox().CheckIntersect(future_bbox))
                { 
                    //collision if one of the bbox was outside the other one,
                    //and inside after moving
                    if(object->GetBbox().CheckFutureCollision(future_bbox,
                                                       o.GetBbox(),
                                                       direction_of_collision)){
                                                  
                        collisions_in_4_directions[direction_of_collision] = &o.GetBbox();
                        ++nb_of_collisions_in_4_directions[direction_of_collision];
                    }
                    
                    if(o.GetUsable()){
                        //o.ReceiveMessage(Message{object, kMsg_Open, 0, 0.0f});
                        controls->AddObjectCollision(&o);
                        if(o.GetUsable()->GetState() == kObjectState_Open){
                            collisions_in_4_directions[direction_of_collision] = nullptr;
                            --nb_of_collisions_in_4_directions[direction_of_collision];
                        }
                    }
                }
                
                
            }
        }
        
        for(GameObject &o  : npcs_list){
            eDirection direction_of_collision = kDirection_None;
            
            collision = object->GetBbox().CheckFutureCollision(future_bbox,
                                                   o.GetBbox(),
                                                   direction_of_collision);
            
            if(collision == true){
                controls->AddObjectCollision(&o);
                collisions_in_4_directions[direction_of_collision] = &o.GetBbox();
                ++nb_of_collisions_in_4_directions[direction_of_collision];
            }
        }
        
        
                
        
        if(collisions_in_4_directions[kDirection_Down]){
            float up = collisions_in_4_directions[kDirection_Down]->GetUp();
            movement.y = up - object->GetBbox().GetDown() - 5;
            float left = collisions_in_4_directions[kDirection_Down]->GetLeft();
            float right = collisions_in_4_directions[kDirection_Down]->GetRight();
            if(nb_of_collisions_in_4_directions[kDirection_Down] == 1 &&
               movement.x == 0){
                if(object->GetBbox().GetRight() - left < 30){
                    movement.x -= 3;
                }
                if(right - object->GetBbox().GetLeft() < 30){
                    movement.x += 3;
                }
            }
        }

        if(collisions_in_4_directions[kDirection_Up]){
            float down = collisions_in_4_directions[kDirection_Up]->GetDown();
            movement.y = down - object->GetBbox().GetUp() + 5;
            float left = collisions_in_4_directions[kDirection_Up]->GetLeft();
            float right = collisions_in_4_directions[kDirection_Up]->GetRight();

            if(nb_of_collisions_in_4_directions[kDirection_Up] == 1 &&
               movement.x == 0){
                if(object->GetBbox().GetRight() - left < 30){
                    movement.x -= 3;
                }
                if(right - object->GetBbox().GetLeft() < 30){
                    movement.x += 3;
                }
            }
        }

        if(collisions_in_4_directions[kDirection_Left]){

            float right = collisions_in_4_directions[kDirection_Left]->GetRight();
            float down = collisions_in_4_directions[kDirection_Left]->GetDown();
            float up = collisions_in_4_directions[kDirection_Left]->GetUp();

            movement.x =  right - object->GetBbox().GetLeft() + 5;

            if(nb_of_collisions_in_4_directions[kDirection_Left] == 1 &&
               movement.y== 0){
                if(down - object->GetBbox().GetUp() < 30){
                    movement.y += 3;
                }
                if(object->GetBbox().GetDown() - up < 30){
                    movement.y -= 3;
                }
            }
        }

        if(collisions_in_4_directions[kDirection_Right]){
            float left = collisions_in_4_directions[kDirection_Right]->GetLeft();
            float down = collisions_in_4_directions[kDirection_Right]->GetDown();
            float up = collisions_in_4_directions[kDirection_Right]->GetUp();

            movement.x =   left - object->GetBbox().GetRight() - 5;

            if(nb_of_collisions_in_4_directions[kDirection_Right] == 1 &&
               movement.y== 0){
                if(down - object->GetBbox().GetUp() < 30){
                    movement.y += 3;
                }
                if(object->GetBbox().GetDown() - up < 30){
                    movement.y -= 3;
                }
            }
        }

        controls->SetMovement(movement);
    }
}


