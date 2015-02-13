#ifndef MATH_H
#define MATH_H

#include <SFML/System/Vector2.hpp>

//pythagore
float DistanceBetween2Points(sf::Vector2f first,
                             sf::Vector2f second){
    return ((second.x - first.x) * (second.x - first.x) +
            (second.y - first.y) * (second.y - first.y));
}

float PythagorasDistance(sf::Vector2f point){
    return sqrt(point.x * point.x +
            point.y * point.y);
}

#endif // MATH_H
