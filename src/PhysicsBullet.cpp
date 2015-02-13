#include "PhysicsBullet.h"
#include "GameObject.h"
#include "GameData.h"
#include "Maths.h"

PhysicsBullet::PhysicsBullet(const float angle) :
    angle_(angle),
    distance_travelled_(0.0f),
    max_distance_(2000.0f)
{
    //ctor
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
    float speed = 5;
    sf::Vector2f movement{static_cast<float>(speed * cos(angle_)),
                          static_cast<float>(speed * sin(angle_))};

    object->Move(movement);


    distance_travelled_ += PythagorasDistance(movement);

    if(distance_travelled_ > max_distance_){
        object->Die();
        return false;
    }

    return true;
}