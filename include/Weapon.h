/* 
 * File:   Weapon.h
 * Author: John
 *
 * Created on 14 février 2015, 03:02
 */

#ifndef WEAPON_H
#define	WEAPON_H

class Weapon {
public:
    Weapon(int bullet_speed, int shot_delay, int bullet_damage);
    virtual ~Weapon();
    virtual void Shoot() = 0;
    
    void AddBullets(const int quantity){
        bullets += quantity;
    }
    
    bool CanShoot() const;
protected:
    int bullet_speed_;
    int shot_delay_;
    int last_shot_;
    int bullet_damage_;
    int bullets;
};

#endif	/* WEAPON_H */

