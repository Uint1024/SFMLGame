#include <iostream>
#include "Player.h"

Player::Player() :
    ConcreteObject(sf::Vector2f(0.0f, 0.0f), sf::Vector2u(0,0))
{
    //ctor
}

Player::Player(const sf::Vector2f& position) :
    ConcreteObject(sf::Vector2f(position.x - 20, position.y - 20), sf::Vector2u(40,40)){
}

Player::~Player()
{
    //dtor
}



void
Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f{40, 40});
    rect.setFillColor(sf::Color(100, 100, 100));
    rect.setPosition(bbox_.GetPosition());

    target.draw(rect);
}

void
Player::Shoot(std::list<Projectile>& projectiles, const float angle_to_mouse){
    projectiles.emplace_back(Projectile(bbox_.GetPosition(), angle_to_mouse));
}
