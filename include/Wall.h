#ifndef WALL_H
#define WALL_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "ConcreteObject.h"

class Wall : public sf::Drawable, public ConcreteObject
{
    public:
        Wall(const sf::Vector2f& position);
        virtual ~Wall();
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const override;
    protected:
    private:
};

#endif // WALL_H
