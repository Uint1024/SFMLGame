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
    UsableComponent(kObjectState_Locked)
{
}

DoorComponent::~DoorComponent() {
}

void 
DoorComponent::Use(GameObject* user, GameObject* used) {
    if(IsUsed()){
        state_ = kObjectState_Open;
        std::cout << "hey lamo" << std::endl;
    }
    if(user->GetControls()->GetCanUnlockEveryDoor()){
        state_ = kObjectState_Open;
    }else{
        use_timer_ += g_delta_time;
        
    }
}
