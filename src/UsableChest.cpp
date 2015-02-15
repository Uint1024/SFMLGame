/* 
 * File:   UsableChest.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 17:48
 */

#include "UsableChest.h"
#include "GameObject.h"
#include "InventoryComponent.h"

UsableChest::UsableChest() :
UsableComponent(kObjectState_Close){
}


UsableChest::~UsableChest() {
}

void UsableChest::Use(GameObject* user, GameObject* used) {
    use_timer_ += g_delta_time;
    if(IsUsed()){
        if(used->GetInventory()->GetCurrentWeapon()){
            if(user->GetInventory()->IsInventoryFull()){
                Weapon* current_weapon_in_chest = used->GetInventory()->GetCurrentWeapon();
                used->GetInventory()->SetCurrentWeapon(user->GetInventory()->GetCurrentWeapon());
                user->GetInventory()->RemoveWeaponFromInventory(user->GetInventory()->GetCurrentWeaponId());
                user->GetInventory()->AddWeapon(current_weapon_in_chest);
            }
            else{
                user->GetInventory()->AddWeapon(used->GetInventory()->GetCurrentWeapon());
                used->GetInventory()->RemoveCurrentWeapon();
            }
            /*
            if(user->GetInventory()->GetCurrentWeapon()){
                Weapon* current_weapon_in_chest = used->GetInventory()->GetCurrentWeapon();
                used->GetInventory()->SetCurrentWeapon(user->GetInventory()->GetCurrentWeapon());
                user->GetInventory()->SetCurrentWeapon(current_weapon_in_chest);
            }
            else{
                user->GetInventory()->AddWeapon(used->GetInventory()->GetCurrentWeapon());
                used->GetInventory()->RemoveCurrentWeapon();
            }*/
        }

        use_timer_ = 0.0;
    }
    
    
}
