#ifndef GROUND_H
#define GROUND_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Ground : public sf::Drawable
{
    public:
        Ground(const eTexture texture);
        virtual ~Ground();
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const override;
        inline eTexture GetTextureId(){
            return texture_;
        }
    protected:
    private:
        eTexture texture_;
};

#endif // GROUND_H
