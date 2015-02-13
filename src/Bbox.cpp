#include <iostream>
#include "Bbox.h"

Bbox::Bbox(const sf::Vector2f& position, const sf::Vector2f& dimensions) :
   up_(position.y), right_(position.x + dimensions.x),
   down_(position.y + dimensions.y), left_(position.x),
   width_(dimensions.x), height_(dimensions.y)
{
}

Bbox::~Bbox()
{
    //dtor
}

void
Bbox::Move(const sf::Vector2f& movement)
{
    left_ += movement.x;
    up_ += movement.y;
    down_ += movement.y;
    right_ += movement.x;
}

void
Bbox::MoveTo(const sf::Vector2f& position)
{
    down_ = position.y + (up_ - down_);
    right_ = position.x + (right_ - left_);
    left_ = position.x;
    up_ = position.y;
}

bool
Bbox::CollidesWithBbox(Bbox& other_bbox){
    return !(left_ > other_bbox.right_ ||
          right_ < other_bbox.left_ ||
          up_ > other_bbox.down_ ||
          down_ < other_bbox.up_);
}


bool
Bbox::CheckFutureCollision(sf::Vector2f movement,
                            Bbox& other_bbox,
                            eDirection& direction_of_collision){
    Bbox future_bbox = *this;
    future_bbox.Move(movement);
    eDirection current_position = kDirection_None;

    if(right_ <= other_bbox.left_)
    {
        current_position = kDirection_Left;
    }
    else if(left_ >= other_bbox.right_)
    {
        current_position = kDirection_Right;
    }
    else if(down_ <= other_bbox.up_)
    {
        current_position = kDirection_Up;
    }
    else if(up_  >= other_bbox.down_)
    {
        current_position = kDirection_Down;
    }


    if(current_position == kDirection_Up &&
          future_bbox.down_ > other_bbox.up_ &&
          future_bbox.up_ < other_bbox.up_ &&
          future_bbox.right_ > other_bbox.left_ &&
          future_bbox.left_ < other_bbox.right_)
    {
        direction_of_collision = kDirection_Down;
        return true;
    }
    else if(current_position == kDirection_Down &&
          future_bbox.up_ < other_bbox.down_ &&
          future_bbox.down_ > other_bbox.down_ &&
          future_bbox.right_ > other_bbox.left_ &&
          future_bbox.left_ < other_bbox.right_)
    {
        direction_of_collision = kDirection_Up;
        return true;
    }
    else if(current_position == kDirection_Left &&
          future_bbox.right_ > other_bbox.left_ &&
          future_bbox.left_ < other_bbox.left_ &&
          future_bbox.down_ > other_bbox.up_ &&
          future_bbox.up_ < other_bbox.down_)
    {
        direction_of_collision = kDirection_Right;
        return true;
    }
    else if(current_position == kDirection_Right &&
          future_bbox.left_ < other_bbox.right_ &&
          future_bbox.right_ > other_bbox.right_ &&
          future_bbox.down_ > other_bbox.up_ &&
          future_bbox.up_ < other_bbox.down_)
    {
        direction_of_collision = kDirection_Left;
        return true;
    }
    direction_of_collision = kDirection_None;
    return false;
}
