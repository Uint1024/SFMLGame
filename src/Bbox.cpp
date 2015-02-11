#include "Bbox.h"

Bbox::Bbox(const sf::Vector2f& position, const sf::Vector2u& dimensions) :
   up_(position.y), right_(position.x + dimensions.x),
   down_(position.y + dimensions.y), left_(position.x)

{

}

Bbox::~Bbox()
{
    //dtor
}

void
Bbox::Move(const sf::Vector2f& movement)
{
    left_ += movement.x;
    up_ += movement.y;
    down_ += movement.y;
    right_ += movement.x;
}

void
Bbox::MoveTo(const sf::Vector2f& position)
{
    down_ = position.y + (up_ - down_);
    right_ = position.x + (right_ - left_);
    left_ = position.x;
    up_ = position.y;
}
