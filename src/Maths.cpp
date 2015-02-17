#include <iostream>
#include <cmath>
#include "Maths.h"

float DistanceBetween2Points(const sf::Vector2f& first,
                             const sf::Vector2f& second){
    return sqrt(((second.x - first.x) * (second.x - first.x) +
            (second.y - first.y) * (second.y - first.y)));
}

float PythagorasDistance(const sf::Vector2f& point){
    float ret = sqrt(point.x * point.x +
            point.y * point.y);
    return ret;
}

float ConvertRadiansToDegrees(const float radians){
    return radians * RadianToDegree;
}

float AngleBetween2Points(const sf::Vector2f& first,
                             const sf::Vector2f& second){
    return atan2(second.y - first.y, second.x - first.x);
}
