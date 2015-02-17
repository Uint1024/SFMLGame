#include "GUI.h"

GUI::GUI(const sf::Vector2f& position, const sf::Vector2f& size) :
bbox_(position, size)
{
    
}

void 
GUI::Move(sf::Vector2f movement) {
    bbox_.Move(movement);
}
