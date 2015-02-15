/* 
 * File:   UseComponent.h
 * Author: John
 *
 * Created on 14 février 2015, 00:39
 */

#ifndef USECOMPONENT_H
#define	USECOMPONENT_H

#include "Globals.h"


class GameObject;

class UsableComponent {
public:
    UsableComponent(eObjectState state);
    UsableComponent(const UsableComponent& orig);
    virtual ~UsableComponent();
    virtual void Use(GameObject* user, GameObject* used) = 0;
    eObjectState GetState() const {
        return state_;
    }
    bool IsUsed(){
        return use_timer_ > time_to_use_;
    }
    
    void SetState(const eObjectState state) {
        state_ = state;
    }
protected:
    eObjectState state_;
    float time_to_use_;
    float use_timer_;
private:
    
};

#endif	/* USECOMPONENT_H */

