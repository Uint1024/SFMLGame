#include "Wall.h"


Wall::~Wall()
{
    //dtor
}

Wall::Wall(const sf::Vector2f& position)
{

}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f{static_cast<float>(g_tile_size.x),
                              static_cast<float>(g_tile_size.y)});
    rect.setFillColor(sf::Color(60, 60, 60));
    rect.setPosition(bbox_.GetPosition());

    target.draw(rect);
}
