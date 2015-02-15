#ifndef BBOX_H
#define BBOX_H
#include <SFML/System.hpp>
#include "Globals.h"

class Bbox
{
    public:
        Bbox();
        Bbox(const sf::Vector2f& position, const sf::Vector2f& dimensions);
        virtual ~Bbox();
        void Move(const sf::Vector2f& movement);
        void MoveTo(const sf::Vector2f& position);
        bool CheckFutureCollision(  Bbox& future_bbox,
                                    Bbox& other_bbox,
                                    eDirection& direction_of_collision);
        bool CheckIntersect(Bbox& other_bbox);
        
        inline void SetPosition(const sf::Vector2f& position){
            up_ = position.y;
            left_ = position.x;
        }

        inline sf::Vector2f GetSize() const{
            return {(right_ - left_),
                    (down_ - up_)};
        }

        inline sf::Vector2f GetPosition() const{
            return {left_, up_};
        }

        inline float GetLeft() const{
            return left_;
        }

        inline float GetRight() const{
            return right_;
        }

        inline float GetUp() const{
            return up_;
        }

        inline float GetDown() const{
            return down_;
        }

    protected:
    private:
        float up_, right_, down_, left_, width_, height_;
};

#endif // BBOX_H
