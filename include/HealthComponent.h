/* 
 * File:   HealthComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 14:07
 */

#ifndef HEALTHCOMPONENT_H
#define	HEALTHCOMPONENT_H
#include "GameObject.h"

class HealthComponent {
public:
    HealthComponent();
    HealthComponent(const HealthComponent& orig);
    virtual ~HealthComponent();
    virtual void Update(GameObject* object);
    void TakeDamage(const int damage){
        hp_ -= damage;
    }
    
    bool IsAlive() const{
        return hp_ > 0;
    }
private:
    int hp_;
    
};

#endif	/* HEALTHCOMPONENT_H */

