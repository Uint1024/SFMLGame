/* 
 * File:   Weapon.h
 * Author: John
 *
 * Created on 14 février 2015, 03:02
 */

#ifndef WEAPON_H
#define	WEAPON_H
#include <SFML/System/Vector2.hpp>
#include "Globals.h"
#include "GameData.h"
class Weapon {
public:
    Weapon(int bullet_speed, int shot_delay, int bullet_damage,
            sf::Vector2f bullet_size, eTexture bullet_texture,
            bool burning);
    virtual ~Weapon();
    virtual void Shoot(GameData& game_data, const float angle,
                       const sf::Vector2f& position) = 0;
    
    void AddBullets(const int quantity){
        bullets += quantity;
    }
    
    bool CanShoot() const;
    
    int GetBulletDamage() const {
        return bullet_damage_;
    }

    sf::Vector2f GetBulletSize() const {
        return bullet_size_;
    }

    int GetBulletSpeed() const {
        return bullet_speed_;
    }

    int GetBullets() const {
        return bullets;
    }

    int GetLastShot() const {
        return last_shot_;
    }

    int GetShotDelay() const {
        return shot_delay_;
    }
    
    eTexture GetBulletTexture() const {
        return bullet_texture_;
    }
    
    bool IsBurning() const {
        return burning_;
    }



protected:
    int bullet_speed_;
    int shot_delay_;
    int last_shot_;
    int bullet_damage_;
    int bullets;
    sf::Vector2f bullet_size_;
    eTexture bullet_texture_;
    bool burning_;
};

#endif	/* WEAPON_H */

