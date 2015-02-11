#include "ConcreteObject.h"

ConcreteObject::ConcreteObject(const sf::Vector2f& position,
                               const sf::Vector2u& dimensions) :
    bbox_(position, dimensions)
{
    //ctor
}

ConcreteObject::~ConcreteObject()
{
    //dtor
}

void
ConcreteObject::Move(const sf::Vector2f& movement)
{
    bbox_.Move(movement);
}
