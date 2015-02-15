/* 
 * File:   WeaponFireStaff.h
 * Author: John
 *
 * Created on 14 février 2015, 18:49
 */

#ifndef WEAPONFIRESTAFF_H
#define	WEAPONFIRESTAFF_H
#include "Weapon.h"
#include "GameData.h"

class WeaponFireStaff : public Weapon{
public:
    WeaponFireStaff();
    virtual ~WeaponFireStaff();

    virtual void Shoot(GameData& game_data, const float angle, 
            const sf::Vector2f& position);

private:

};

#endif	/* WEAPONFIRESTAFF_H */

