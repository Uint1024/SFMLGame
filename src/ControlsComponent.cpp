#include <list>
#include <iostream>
#include "ControlsComponent.h"
#include "GameObject.h"
ControlsComponent::ControlsComponent(bool can_unlock_every_door):
    movement_(0.0f,0.0f),
can_unlock_every_door_(can_unlock_every_door)
{
    //ctor
}

ControlsComponent::~ControlsComponent()
{

}

void
ControlsComponent::AddObjectCollision(GameObject* object){
    
    objects_collisions_list_.push_back(object);
    
}