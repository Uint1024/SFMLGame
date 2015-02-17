#ifndef MATH_H
#define MATH_H

#include <SFML/System/Vector2.hpp>

const float RadianToDegree = 57.295;
//pythagore
float DistanceBetween2Points(const sf::Vector2f& first,
                             const sf::Vector2f& second);
float AngleBetween2Points(const sf::Vector2f& first,
                             const sf::Vector2f& second);
float PythagorasDistance(const sf::Vector2f& point);
float ConvertRadiansToDegrees(const float radians);

extern const float PI;

#endif // MATH_H
