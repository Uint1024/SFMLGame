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
        bool CheckPointIntersect(sf::Vector2f point);
        bool CheckPointIntersecti(sf::Vector2i point);
        void SetPosition(const sf::Vector2f& position){
            up_ = position.y;
            left_ = position.x;
        }
        
        void SetHeight(const int height){
            height_ = height;
            down_ = up_ + height;
            
        }
        
        void SetWidth(const int width){
            width_ = width;
            right_ = left_ + width;
            
        }

        sf::Vector2f GetSize() const{
            return {width_, height_};
        }

        sf::Vector2f GetPosition() const{
            return {left_, up_};
        }

        float GetLeft() const{
            return left_;
        }

        float GetRight() const{
            return right_;
        }

        float GetUp() const{
            return up_;
        }

        float GetDown() const{
            return down_;
        }

    protected:
    private:
        float up_, right_, down_, left_, width_, height_;
};

#endif // BBOX_H
