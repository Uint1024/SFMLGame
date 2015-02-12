#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "ConcreteObject.h"

class Projectile : public sf::Drawable, public ConcreteObject
{
    public:
        Projectile(const sf::Vector2f& position, const float angle_to_mouse);
        virtual ~Projectile();
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const override;
        bool Update();

        inline  bool IsDead() const{
            return dead_;
        }
    protected:
    private:
         float angle_;
         bool dead_;
        float distance_travelled_;
        float max_distance_;



};

#endif // PROJECTILE_H
