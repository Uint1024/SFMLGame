/* 
 * File:   ArrowMachinegun.h
 * Author: John
 *
 * Created on 14 février 2015, 03:07
 */

#ifndef ARROWMACHINEGUN_H
#define	ARROWMACHINEGUN_H

#include "Weapon.h"


class ArrowMachinegun : public Weapon {
public:
    ArrowMachinegun();
    virtual ~ArrowMachinegun();
    void Shoot() override;
private:

};

#endif	/* ARROWMACHINEGUN_H */

