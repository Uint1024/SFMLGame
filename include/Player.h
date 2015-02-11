#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "ConcreteObject.h"
#include "Projectile.h"

class Player : public sf::Drawable, public ConcreteObject
{
    public:
        Player();
        Player(const sf::Vector2f& position);
        virtual ~Player();


        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void Shoot(std::list<Projectile>& projectiles, const float angle_to_mouse);
    protected:
    private:

};

#endif // PLAYER_H
