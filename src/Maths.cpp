#include <cmath>
#include "Maths.h"

float DistanceBetween2Points(sf::Vector2f first,
                             sf::Vector2f second){
    return ((second.x - first.x) * (second.x - first.x) +
            (second.y - first.y) * (second.y - first.y));
}

float PythagorasDistance(sf::Vector2f point){
    return sqrt(point.x * point.x +
            point.y * point.y);
}

float ConvertRadiansToDegrees(const float radians){
    return radians * RadianToDegree;
}

float AngleBetween2Points(sf::Vector2f first,
                             sf::Vector2f second){
    return atan2(second.y - first.y, second.x - first.x);
}
