#ifndef BBOX_H
#define BBOX_H
#include <SFML/System.hpp>

class Bbox
{
    public:
        Bbox(const sf::Vector2f& position, const sf::Vector2u& dimensions);
        virtual ~Bbox();
        void Move(const sf::Vector2f& movement);
        void MoveTo(const sf::Vector2f& position);

        inline sf::Vector2i GetSize() const{
            return {static_cast<int>(right_ - left_),
                    static_cast<int>(down_ - up_)};
        }

        inline sf::Vector2f GetPosition() const{
            return {left_, up_};
        }

    protected:
    private:
        float up_, right_, down_, left_;
};

#endif // BBOX_H
