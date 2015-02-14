/* 
 * File:   UseComponent.h
 * Author: John
 *
 * Created on 14 février 2015, 00:39
 */

#ifndef USECOMPONENT_H
#define	USECOMPONENT_H

class GameObject;

class UsableComponent {
public:
    UsableComponent();
    UsableComponent(const UsableComponent& orig);
    virtual ~UsableComponent();
    virtual void Use(GameObject* object) = 0;
private:

};

#endif	/* USECOMPONENT_H */

