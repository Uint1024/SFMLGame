/* 
 * File:   InventoryComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 21:07
 */

#ifndef INVENTORYCOMPONENT_H
#define	INVENTORYCOMPONENT_H
#include <vector>
#include "Weapon.h"

class GameObject;
class InventoryComponent {
public:
    InventoryComponent();
    InventoryComponent(const InventoryComponent& orig);
    virtual ~InventoryComponent();
    virtual void Update(GameObject* object);
    
    auto& GetWeapons() {
        return weapons_;
    }
    void AddWeapon(Weapon* weapon){
       if(weapons_.size() < 2){
           weapons_.push_back(weapon);
       }
    }
private:
    std::vector<Weapon*> weapons_;
    
};

#endif	/* INVENTORYCOMPONENT_H */

