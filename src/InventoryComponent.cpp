/* 
 * File:   InventoryComponent.cpp
 * Author: John
 * 
 * Created on 13 février 2015, 21:07
 */

#include "InventoryComponent.h"
#include "GameObject.h"


InventoryComponent::InventoryComponent(Weapon* weapon) :
weapons_{nullptr, nullptr},
current_weapon_(nullptr)
{    
    AddWeapon(weapon);
}

InventoryComponent::InventoryComponent(const InventoryComponent& orig) {
}

InventoryComponent::~InventoryComponent() {
}

void
InventoryComponent::Update(GameObject* object){
    

}