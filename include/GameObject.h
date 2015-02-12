#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Globals.h"

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        inline eObjectType GetType() const{
            return type;
        }
    protected:

    private:
        eObjectType type;
};

#endif // GAMEOBJECT_H
