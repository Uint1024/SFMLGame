/* 
 * File:   BulletComponent.h
 * Author: John
 *
 * Created on 14 février 2015, 16:38
 */

#ifndef BULLETCOMPONENT_H
#define	BULLETCOMPONENT_H

class Weapon;
class BulletComponent {
public:
    BulletComponent(Weapon* parent);
    BulletComponent(const BulletComponent& orig);
    virtual ~BulletComponent();
    Weapon* GetParent() const {
        return parent_;
    }

private:
    Weapon* parent_;
};

#endif	/* BULLETCOMPONENT_H */

