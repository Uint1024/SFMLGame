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
    void Use(GameObject* object);
    bool IsUnlocked(){
        return unlock_timer_ > time_to_unlock_;
    }
    private:
        float time_to_unlock_;
        float unlock_timer_;

};

#endif	/* DOORCOMPONENT_H */

