#include "PhysicsBullet.h"
#include "GameObject.h"
#include "GameData.h"
#include "Maths.h"

PhysicsBullet::PhysicsBullet(const float angle) :
    angle_(angle),
    distance_travelled_(0.0f),
    max_distance_(1200.0f)
{
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
    
    float speed = 10;
    sf::Vector2f movement{static_cast<float>(speed * cos(angle_)),
                          static_cast<float>(speed * sin(angle_))};

    object->Move(movement);

    distance_travelled_ += PythagorasDistance(movement);

    if(distance_travelled_ > max_distance_){
        object->Die();
        return false;
    }
    
    std::cout << angle_ << std::endl;
    //angle_ = 3.14 + 3.14/2.0f;
    
    
    std::vector<GameObject*>& walls_map = game_data.GetWalls();
    auto& npcs = game_data.GetNpcs();
    eDirection direction_of_collision = kDirection_None;
    std::array<Bbox*, kDirection_Count> collisions_in_4_directions{nullptr};
    std::array<int, kDirection_Count> nb_of_collisions_in_4_directions{0};
        
    for(GameObject* o : walls_map){
        if(o && object->GetBbox().CheckFutureCollision(movement,
                                               o->GetBbox(),
                                               direction_of_collision)){
            collisions_in_4_directions[direction_of_collision] = &o->GetBbox();        
            ++nb_of_collisions_in_4_directions[direction_of_collision];
        }
    }
    
    distance_travelled_ = max_distance_ - 400;

    if(collisions_in_4_directions[kDirection_Down]){
        if(nb_of_collisions_in_4_directions[kDirection_Left] < 2){
                collisions_in_4_directions[kDirection_Left] = nullptr;
            }
        if(nb_of_collisions_in_4_directions[kDirection_Right] < 2){
            collisions_in_4_directions[kDirection_Right] = nullptr;
        }
    }
    if(collisions_in_4_directions[kDirection_Left] ||
            collisions_in_4_directions[kDirection_Right]){
        angle_ = -(angle_ - PI);
    }
    
    for(auto &npc : npcs){
        if(object->GetBbox().CollidesWithBbox(npc.GetBbox())){
            
            object->Die();
            
        }
    }
    return true;
}
