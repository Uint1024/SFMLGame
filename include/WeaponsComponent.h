/* 
 * File:   WeaponsComponent.h
 * Author: John
 *
 * Created on 14 février 2015, 03:18
 */

#ifndef WEAPONSCOMPONENT_H
#define	WEAPONSCOMPONENT_H
#include "GameData.h"

class WeaponsComponent {
public:
    WeaponsComponent();
    WeaponsComponent(const WeaponsComponent& orig);
    virtual ~WeaponsComponent();
    virtual void Shoot(GameData& game_data, float angle);
private:

};

#endif	/* WEAPONSCOMPONENT_H */

