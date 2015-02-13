#ifndef GROUND_H
#define GROUND_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Ground
{
    public:
        Ground(const eTexture texture);
        virtual ~Ground();
        inline eTexture GetTextureId(){
            return texture_;
        }
    protected:
    private:
        eTexture texture_;
};

#endif // GROUND_H
