/* 
 * File:   UsableChest.h
 * Author: John
 *
 * Created on 14 février 2015, 17:48
 */

#ifndef USABLECHEST_H
#define	USABLECHEST_H

#include "UseComponent.h"


class UsableChest : public UsableComponent{
public:
    UsableChest();
    virtual ~UsableChest();

    virtual void Use(GameObject* user, GameObject* used) override;

private:

};

#endif	/* USABLECHEST_H */

