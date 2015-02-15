/* 
 * File:   UseComponent.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 00:39
 */

#include "UseComponent.h"

UsableComponent::UsableComponent(eObjectState state) :
state_(state), time_to_use_(1.5f), use_timer_(0.0f){
}

UsableComponent::UsableComponent(const UsableComponent& orig) {
}

UsableComponent::~UsableComponent() {
}

void 
UsableComponent::Use(GameObject* user, GameObject* used) {
    
}
