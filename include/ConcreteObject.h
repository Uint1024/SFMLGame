#ifndef CONCRETEOBJECT_H
#define CONCRETEOBJECT_H
#include "Bbox.h"
#include <SFML/System/Vector2.hpp>

class ConcreteObject
{
    public:
        ConcreteObject(const sf::Vector2f& movement,
                  const sf::Vector2u& dimensions);
        virtual ~ConcreteObject();
        void Move(const sf::Vector2f& movement);
        inline sf::Vector2f GetPosition() const{
            bbox_.GetPosition();
        }
    protected:
        Bbox bbox_;

};

#endif // CONCRETEOBJECT_H
