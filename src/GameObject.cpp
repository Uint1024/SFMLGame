#include "GameObject.h"
#include "Globals.h"
#include "Engine.h"
#include "GameData.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "ControlsComponent.h"

GameObject::GameObject(sf::Vector2f position,
                       sf::Vector2f dimensions,
                       PhysicsComponent* physics,
                       GraphicsComponent* graphics,
                       ControlsComponent* controls) :
    physics_(physics),
    graphics_(graphics),
    controls_(controls),
    alive_(true),
    bbox_(position, dimensions)
{
    MoveTo(position);
    //this->setPosition(position);
    //bbox_.setPosition(position);
}

GameObject::GameObject(sf::Vector2f position,
                       sf::Vector2f dimensions,
                       PhysicsComponent* physics,
                       GraphicsComponent* graphics) :
    physics_(physics),
    graphics_(graphics),
    controls_(nullptr),
    alive_(true),
    bbox_(position, dimensions)
{
    MoveTo(position);
}



GameObject::~GameObject()
{
    //dtor
}

//return false if the object is dead after update
bool
GameObject::Update(Engine& engine, GameData& game_data){
    if(graphics_){
        graphics_->Update(this, engine);
    }

    if(controls_){
        controls_->Update(this, engine, game_data);
    }

    if(physics_){
        if(g_game_state == kGameState_Playing){
            physics_->Update(this, game_data, controls_, engine);
        }
    }

    return alive_;
}


void
GameObject::Move(const sf::Vector2f& movement){
    move(movement);
    bbox_.Move(movement);
}

void
GameObject::MoveTo(const sf::Vector2f& position){
    this->setPosition(position);
    bbox_.SetPosition(position);
}
