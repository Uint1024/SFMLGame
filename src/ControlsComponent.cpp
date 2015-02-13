#include "ControlsComponent.h"

ControlsComponent::ControlsComponent(InputManager& input_manager):
    input_manager_(input_manager),
    movement_(0.0f,0.0f)
{
    //ctor
}

ControlsComponent::~ControlsComponent()
{
    //dtor
}

