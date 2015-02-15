/* 
 * File:   BulletComponent.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 16:38
 */

#include "BulletComponent.h"
#include "Weapon.h"
BulletComponent::BulletComponent(Weapon* parent) :
parent_(parent){
}

BulletComponent::BulletComponent(const BulletComponent& orig) {
}

BulletComponent::~BulletComponent() {
}

