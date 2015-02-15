#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicsVisible.h"
#include "Engine.h"
#include "GameObject.h"

GraphicsVisible::GraphicsVisible(const eTexture texture_id) :
    texture_id_(texture_id)
{
    //ctor
}

GraphicsVisible::~GraphicsVisible()
{
    //dtor
}

void
GraphicsVisible::Update(GameObject* object, Engine& engine)
{
    sf::RectangleShape rect(object->GetBbox().GetSize());
    rect.setPosition(object->GetBbox().GetPosition());
    rect.setFillColor(engine.GetObjectsColors()[texture_id_]);
    
    sf::Transform t;
    t.rotate(object->getRotation(),
             object->getPosition().x + object->GetBbox().GetSize().x/2,
             object->getPosition().y + object->GetBbox().GetSize().y/2);
    engine.GetWindow().draw(rect, t);
    
    
    //engine.GetWindow().draw(bbox);
}
