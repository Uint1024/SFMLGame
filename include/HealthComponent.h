/* 
 * File:   HealthComponent.h
 * Author: John
 *
 * Created on 13 février 2015, 14:07
 */

#ifndef HEALTHCOMPONENT_H
#define	HEALTHCOMPONENT_H
#include "GameObject.h"
#include "Engine.h"
#include "GameData.h"

class HealthComponent {
public:
    HealthComponent();
    HealthComponent(const HealthComponent& orig);
    virtual ~HealthComponent();
    virtual void Update(GameObject* object, Engine& engine,
                              GameData& game_data);
    inline bool IsDead() {
        return hp <= 0;
    }
private:
    int hp;
    
};

#endif	/* HEALTHCOMPONENT_H */

