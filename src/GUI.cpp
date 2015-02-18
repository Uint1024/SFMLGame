#include <iostream>
#include "GUI.h"

GUI::GUI(const sf::Vector2f& position, const sf::Vector2f& size) :
bbox_(position, size),
position_(position)
{
    
}

void 
GUI::Move(const sf::Vector2f& movement) {
    bbox_.Move(movement);
}

void GUI::TestFunction() {
    std::cout << "wtf" << std::endl;
}
