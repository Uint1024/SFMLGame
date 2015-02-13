#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

#include "GameObject.h"
#include "GameData.h"
#include "PhysicsSolid.h"
#include "Bbox.h"


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
        std::vector<GameObject*> walls_map = game_data.GetWalls();
        Bbox temp_bbox = object->GetBbox();
        temp_bbox.Move(movement);
        std::cout << movement.x << std::endl;
        //controls_component generate new bbox
        //if there is no collision detected, replace current bbox

        //array of the Bbox that collide with the object
        std::array<Bbox*, kDirection_Count> collisions_in_4_directions{nullptr};
        for(GameObject* o : walls_map){
            //check temp bbox collisions
            eDirection direction_of_collision = kDirection_None;
            if(o && object->GetBbox().CheckFutureCollision(movement,
                                                   o->GetBbox(),
                                                   direction_of_collision)){

                collisions_in_4_directions[direction_of_collision] = &o->GetBbox();
            }
        }

        if(collisions_in_4_directions[kDirection_Left]){

            float right = collisions_in_4_directions[kDirection_Left]->GetRight();
            movement.x =  right - object->GetBbox().GetLeft();
        }

        if(collisions_in_4_directions[kDirection_Right]){

            float left = collisions_in_4_directions[kDirection_Right]->GetLeft();
            movement.x =   left - object->GetBbox().GetRight();
        }

        if(collisions_in_4_directions[kDirection_Down]){
            float up = collisions_in_4_directions[kDirection_Down]->GetUp();
            movement.y = up - object->GetBbox().GetDown();
        }

        if(collisions_in_4_directions[kDirection_Up]){
            float down = collisions_in_4_directions[kDirection_Up]->GetDown();
            movement.y = down - object->GetBbox().GetUp();
        }

        controls->SetMovement(movement);
    }
}


