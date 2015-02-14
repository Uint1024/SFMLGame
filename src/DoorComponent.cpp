/* 
 * File:   DoorComponent.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 00:48
 */

#include <iostream>
#include "Globals.h"

#include "DoorComponent.h"
#include "GameObject.h"
DoorComponent::DoorComponent() :
    time_to_unlock_(1.5),
    unlock_timer_(0),
    UsableComponent(kObjectState_Locked)
{
}

DoorComponent::~DoorComponent() {
}

void 
DoorComponent::Use(GameObject* object) {
    unlock_timer_ += g_delta_time;
    if(unlock_timer_ > time_to_unlock_){
        state_ = kObjectState_Close;
    }
    std::cout << unlock_timer_ << std::endl;
}
