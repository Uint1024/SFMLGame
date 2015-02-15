/* 
 * File:   DoorComponent.h
 * Author: John
 *
 * Created on 14 février 2015, 00:48
 */

#ifndef DOORCOMPONENT_H
#define	DOORCOMPONENT_H

#include "UseComponent.h"

class GameObject;
class DoorComponent : public UsableComponent {
public:
    DoorComponent();
    virtual ~DoorComponent();
    void Use(GameObject* user, GameObject* used);

    private:


};

#endif	/* DOORCOMPONENT_H */

