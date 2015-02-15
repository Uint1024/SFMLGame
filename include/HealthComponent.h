/* 
 * File:   HealthComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 14:07
 */

#ifndef HEALTHCOMPONENT_H
#define	HEALTHCOMPONENT_H
#include "GameObject.h"
class Weapon;
class HealthComponent {
public:
    HealthComponent(const int hp);
    HealthComponent(const HealthComponent& orig);
    virtual ~HealthComponent();
    virtual void Update(GameObject* object);
    void TakeDamage(const int damage){
        hp_ -= damage;
    }
    
    void GetShot(Weapon* weapon);
    bool IsAlive() const{
        return hp_ > 0;
    }
private:
    int hp_;
    bool burning_;
    float burning_timer_;
    
};

#endif	/* HEALTHCOMPONENT_H */

