#ifndef SOLIDPHYSICS_H
#define SOLIDPHYSICS_H
#include "PhysicsComponent.h"


class PhysicsSolid : public PhysicsComponent
{
    public:
        PhysicsSolid();
        virtual ~PhysicsSolid();
        virtual bool Update(GameObject* object,
                            GameData& game_data,
                            ControlsComponent* controls,
                            Engine& engine) override;
        //Bbox* CheckCollisionWithBbox();
    protected:

    private:

};

#endif // SOLIDPHYSICS_H
