/* 
 * File:   ArrowMachinegun.h
 * Author: John
 *
 * Created on 14 février 2015, 03:07
 */

#ifndef ARROWMACHINEGUN_H
#define	ARROWMACHINEGUN_H

#include "Weapon.h"
#include "GameData.h"

class ArrowMachinegun : public Weapon {
public:
    ArrowMachinegun();
    virtual ~ArrowMachinegun();
    void Shoot(GameData& game_data, const float angle,
                       const sf::Vector2f& position) override;
private:

};

#endif	/* ARROWMACHINEGUN_H */

