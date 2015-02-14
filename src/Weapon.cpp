/* 
 * File:   Weapon.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 03:02
 */

#include "Weapon.h"
#include "Globals.h"
Weapon::Weapon(int bullet_speed, int shot_delay, int bullet_damage) :
bullet_speed_(bullet_speed),
shot_delay_(shot_delay),
last_shot_(0),
bullet_damage_(bullet_damage),
bullets(0)
{
}

Weapon::~Weapon() {
}

bool
Weapon::CanShoot() const{
    return (bullets > 0 && last_shot_ + shot_delay_ > g_game_time);
}