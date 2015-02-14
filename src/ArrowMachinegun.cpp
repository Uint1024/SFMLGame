/* 
 * File:   ArrowMachinegun.cpp
 * Author: John
 * 
 * Created on 14 février 2015, 03:07
 */

#include "ArrowMachinegun.h"
#include "Globals.h"

ArrowMachinegun::ArrowMachinegun() :
Weapon(10, 200, 10){
}


ArrowMachinegun::~ArrowMachinegun() {
}

void 
ArrowMachinegun::Shoot() {
    if(CanShoot()){
        last_shot_ = g_game_time;
        bullets -= 1;
    }
}
