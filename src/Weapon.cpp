/* 
 * File:   Weapon.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 03:02
 */

#include <iostream>
#include "Weapon.h"
#include "Globals.h"
Weapon::Weapon(int bullet_speed, int shot_delay, int bullet_damage,
               sf::Vector2f bullet_size, eTexture bullet_texture,
               bool burning):
bullet_speed_(bullet_speed),
shot_delay_(1),
last_shot_(0),
bullet_damage_(bullet_damage),
bullets(100000000),
bullet_size_(bullet_size),
bullet_texture_(bullet_texture),
burning_(burning)
{
}

Weapon::~Weapon() {
}

bool
Weapon::CanShoot() const{
    return (bullets > 0 && last_shot_ + shot_delay_ < g_game_time);
}