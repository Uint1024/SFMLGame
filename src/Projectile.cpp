#include "Projectile.h"
#include "Maths.h"

Projectile::Projectile(const sf::Vector2f& position, const float angle_to_mouse) :
    ConcreteObject(position, sf::Vector2u(10,10)),
    angle_(angle_to_mouse), dead_(false), distance_travelled_(0.0f),
    max_distance_(2000.0f)
{
    //ctor
}

Projectile::~Projectile()
{
    //dtor
}

void
Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f{20, 20});
    rect.setFillColor(sf::Color(200, 120, 170));
    rect.setPosition(bbox_.GetPosition());

    target.draw(rect);
}

bool
Projectile::Update(){
    float speed = 5;
    sf::Vector2f movement{static_cast<float>(speed * cos(angle_)),
                          static_cast<float>(speed * sin(angle_))};

    bbox_.Move(movement);
    distance_travelled_ += DistanceToPoint(movement);

    if(distance_travelled_ > max_distance_){
        dead_ = true;
    }

    return dead_;
}
