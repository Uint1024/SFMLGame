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
    virtual void Use(GameObject* object) = 0;
    eObjectState GetState() const {
        return state_;
    }
protected:
    eObjectState state_;
private:
    
};

#endif	/* USECOMPONENT_H */

