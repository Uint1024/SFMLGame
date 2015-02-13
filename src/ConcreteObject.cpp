#include "ConcreteObject.h"

ConcreteObject::ConcreteObject()
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
