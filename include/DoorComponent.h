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
    DoorComponent(const DoorComponent& orig);
    virtual ~DoorComponent();
    void Use(GameObject* object);
    private:
        float time_to_open;
        float open_timer;

};

#endif	/* DOORCOMPONENT_H */

