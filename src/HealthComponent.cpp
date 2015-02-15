/* 
 * File:   HealthComponent.cpp
 * Author: John
 * 
 * Created on 13 février 2015, 14:07
 */

#include <iostream>
#include "HealthComponent.h"
#include "Weapon.h"

HealthComponent::HealthComponent(const int hp) :
hp_(hp),
burning_timer_(0.0f),
burning_(false)
{
}

HealthComponent::HealthComponent(const HealthComponent& orig) {
}

HealthComponent::~HealthComponent() {
}

void 
HealthComponent::Update(GameObject* object) {
    if(burning_){     
        burning_timer_ += g_delta_time;
        
        if(burning_timer_ > 0.5f){
            hp_ -= 10;
            burning_timer_ = 0.0f;
        } 
    }
}

void 
HealthComponent::GetShot(Weapon* weapon) {
    hp_ -= weapon->GetBulletDamage();
    if(weapon->IsBurning()){
        burning_ = true;
    }
}
