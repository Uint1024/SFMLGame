#include "Ground.h"


Ground::~Ground()
{
    //dtor
}

Ground::Ground(const eTexture texture) :
    texture_(texture)
{
}

void Ground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
