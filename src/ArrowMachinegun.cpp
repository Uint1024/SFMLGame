/* 
 * File:   ArrowMachinegun.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 03:07
 */

#include <iostream>
#include "ArrowMachinegun.h"
#include "Globals.h"

#include <SFML/System/Vector2.hpp>
#include "GameData.h"
#include "PhysicsBullet.h"
#include "GraphicsVisible.h"
#include "GameObject.h"
#include "BulletComponent.h"

ArrowMachinegun::ArrowMachinegun() :
Weapon(800, 150, 10, sf::Vector2f{30,10}, kTexture_Bullet_Arrow, false){
}


ArrowMachinegun::~ArrowMachinegun() {
}

void 
ArrowMachinegun::Shoot(GameData& game_data, const float angle,
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
