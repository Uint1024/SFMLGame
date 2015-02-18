#include "PhysicsBullet.h"
#include "GameObject.h"
#include "GameData.h"
#include "HealthComponent.h"
#include "Maths.h"
#include "BulletComponent.h"
#include "Globals.h"
#include "UseComponent.h"

PhysicsBullet::PhysicsBullet(const float angle, const float speed) :
    angle_(angle),
    distance_travelled_(0.0f),
    max_distance_(1000000.0f),
    direction_of_collision_(kDirection_None),
    collisions_in_4_directions_{nullptr},
    nb_of_collisions_in_4_directions_{0},
    speed_(speed),
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
    sf::Vector2f velocity_delta = 
                    {velocity_.x * g_delta_time, velocity_.y  * g_delta_time};
    object->Move(velocity_delta,
                 angle_);
    
    Bbox future_bbox = object->GetBbox();
    future_bbox.Move(velocity_delta);
    
    distance_travelled_ += PythagorasDistance(velocity_delta);
    
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
        if(o.GetPhysics() && object->GetBbox().CheckFutureCollision(future_bbox,
                                               o.GetBbox(),
                                               direction_of_collision_)){
            if(!o.GetUsable() || ( o.GetUsable() && o.GetUsable()->GetState() != kObjectState_Open)){
                collisions_in_4_directions_[direction_of_collision_] = &o.GetBbox();        
                ++nb_of_collisions_in_4_directions_[direction_of_collision_];
            }
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
        
        angle_ = -angle_;
        velocity_ = {static_cast<float>(speed_ * cos(angle_)),
              static_cast<float>(speed_ * sin(angle_))};
    }
    
    for(auto &npc : npcs){
        if(object->GetBbox().CheckIntersect(npc.GetBbox())){
            npc.GetHealth()->GetShot(object->GetBullet()->GetParent());
            object->Die();
        }
    }
    return true;
}
