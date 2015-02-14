/* 
 * File:   InventoryComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 21:07
 */

#ifndef INVENTORYCOMPONENT_H
#define	INVENTORYCOMPONENT_H


class GameObject;
class InventoryComponent {
public:
    InventoryComponent();
    InventoryComponent(const InventoryComponent& orig);
    virtual ~InventoryComponent();
    virtual void Update(GameObject* object);
    
private:
    

};

#endif	/* INVENTORYCOMPONENT_H */

