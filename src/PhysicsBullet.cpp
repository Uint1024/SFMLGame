#include "PhysicsBullet.h"
#include "GameObject.h"
#include "GameData.h"
#include "HealthComponent.h"
#include "Maths.h"

PhysicsBullet::PhysicsBullet(const float angle) :
    angle_(angle),
    distance_travelled_(0.0f),
    max_distance_(1200.0f),
    damage_(1),
    direction_of_collision_(kDirection_None),
    collisions_in_4_directions_{nullptr},
    nb_of_collisions_in_4_directions_{0},
    speed_(10),
    movement_{0.0f,0.0f},
    velocity_{static_cast<float>(speed_ * cos(angle)),
              static_cast<float>(speed_ * sin(angle))},
    distance_travelled_per_tick_{PythagorasDistance(velocity_)}
        
{
    distance_travelled_per_tick_ = PythagorasDistance(velocity_);
    if(angle_ < 0){
        angle_ += 6.28f;
    }
}

PhysicsBullet::~PhysicsBullet()
{
    //dtor
}

bool
PhysicsBullet::Update(GameObject* object,
                      GameData& game_data,
                      ControlsComponent* controls,
                      Engine& engine)
{
    object->Move(velocity_);

    distance_travelled_ += distance_travelled_per_tick_;
    if(distance_travelled_ > max_distance_){
        object->Die();
        return false;
    }
        
    auto& walls_map = game_data.GetWalls();
    auto& npcs = game_data.GetNpcs();


    collisions_in_4_directions_ = {nullptr, nullptr, nullptr, nullptr};
    nb_of_collisions_in_4_directions_ = {0,0,0,0};
    
    for(GameObject &o : walls_map){
        direction_of_collision_ = kDirection_None;
        if(object->GetBbox().CheckFutureCollision(velocity_,
                                               o.GetBbox(),
                                               direction_of_collision_)){
            collisions_in_4_directions_[direction_of_collision_] = &o.GetBbox();        
            ++nb_of_collisions_in_4_directions_[direction_of_collision_];
        }
    }

    if(collisions_in_4_directions_[kDirection_Left] ||
            collisions_in_4_directions_[kDirection_Right]){
        angle_ = -(angle_ - PI);
        velocity_ = {static_cast<float>(speed_ * cos(angle_)),
              static_cast<float>(speed_ * sin(angle_))};
    }
    if(collisions_in_4_directions_[kDirection_Up] ||
            collisions_in_4_directions_[kDirection_Down]){
        angle_ = (- angle_) ;
        velocity_ = {static_cast<float>(speed_ * cos(angle_)),
              static_cast<float>(speed_ * sin(angle_))};
    }
    
    for(auto &npc : npcs){
        if(object->GetBbox().CollidesWithBbox(npc.GetBbox())){
            npc.GetHealth()->TakeDamage(damage_);
            object->Die();
            
        }
    }
    return true;
}
