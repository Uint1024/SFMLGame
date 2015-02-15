/* 
 * File:   WeaponFireStaff.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 18:49
 */

#include "WeaponFireStaff.h"
#include "Globals.h"

#include <SFML/System/Vector2.hpp>
#include "GameData.h"
#include "PhysicsBullet.h"
#include "GraphicsVisible.h"
#include "GameObject.h"
#include "BulletComponent.h"


WeaponFireStaff::WeaponFireStaff() :
Weapon(800, 1000, 10, sf::Vector2f{30,30}, kTexture_Bullet_FireBall,
        true){
}

WeaponFireStaff::~WeaponFireStaff() {
}

void 
WeaponFireStaff::Shoot(GameData& game_data, const float angle,
                       const sf::Vector2f& position) {
    
    if(CanShoot()){
        last_shot_ = g_game_time;
        bullets -= 1;
        game_data.GetProjectiles().push_back(
                  GameObject(position,
                             bullet_size_,
                             new PhysicsBullet(angle, bullet_speed_),
                             new GraphicsVisible(bullet_texture_), nullptr,
                             nullptr, nullptr, nullptr, 
                             new BulletComponent(this))); 
    }
}
