#include <list>
#include <iostream>
#include "ControlsComponent.h"
#include "GameObject.h"
ControlsComponent::ControlsComponent():
    movement_(0.0f,0.0f)
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