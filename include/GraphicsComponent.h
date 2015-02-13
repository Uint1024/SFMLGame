#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

class Engine;
class GameObject;
class GraphicsComponent
{
    public:
        GraphicsComponent();
        virtual ~GraphicsComponent();
        virtual void Update(GameObject* object, Engine& engine) = 0;
    protected:
    private:
};

#endif // GRAPHICSCOMPONENT_H
