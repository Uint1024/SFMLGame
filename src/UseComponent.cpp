/* 
 * File:   UseComponent.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 00:39
 */

#include "UseComponent.h"

UsableComponent::UsableComponent(eObjectState state) :
state_(state){
}

UsableComponent::UsableComponent(const UsableComponent& orig) {
}

UsableComponent::~UsableComponent() {
}

void 
UsableComponent::Use(GameObject* object) {
    
}
