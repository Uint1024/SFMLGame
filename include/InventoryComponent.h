/* 
 * File:   InventoryComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 21:07
 */

#ifndef INVENTORYCOMPONENT_H
#define	INVENTORYCOMPONENT_H
#include <vector>
#include <memory>
#include "Weapon.h"

class GameObject;
class InventoryComponent {
public:
    InventoryComponent(Weapon* weapon = nullptr);
    InventoryComponent(const InventoryComponent& orig);
    virtual ~InventoryComponent();
    virtual void Update(GameObject* object);
    
    auto& GetWeapons() {
        return weapons_;
    }
    void AddWeapon(Weapon* weapon){
        if(!weapons_[0]){
           weapons_[0] = weapon;
           current_weapon_ = weapon;
           return;
        }
        if(!weapons_[1]){
            std::cout << "heh" << std::endl;
            weapons_[1] = weapon;
            current_weapon_ = weapon;
            return;
        }
    }
    
    bool IsInventoryFull() const{
        return (weapons_[0] && weapons_[1]);
    }
    
    void RemoveCurrentWeapon(){
        current_weapon_ = nullptr;
    }
    
    //remove weapon without deleting it
    void RemoveWeaponFromInventory(const int inventory_slot){
        weapons_[inventory_slot] = nullptr;
    }
    
    Weapon* GetCurrentWeapon() const {
        return current_weapon_;
    }
    
    void SetCurrentWeapon(Weapon* weapon) {
        current_weapon_ = weapon;
    }
    
    void SetCurrentWeapon(const int inventory_slot) {
        if(weapons_[inventory_slot]){
            current_weapon_ = weapons_[inventory_slot];
        }
        else{
            current_weapon_ = nullptr;
        }
        
        current_weapon_id_ = inventory_slot;
    }
    
    int GetCurrentWeaponId() const {
        return current_weapon_id_;
    }


private:
    std::vector<Weapon*> weapons_;
    Weapon* current_weapon_;
    int current_weapon_id_;
    
};

#endif	/* INVENTORYCOMPONENT_H */

