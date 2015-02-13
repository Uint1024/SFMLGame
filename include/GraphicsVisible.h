#ifndef VISIBLEGRAPHICS_H
#define VISIBLEGRAPHICS_H
#include "GraphicsComponent.h"
#include "Globals.h"

class Engine;
class GraphicsVisible : public GraphicsComponent
{
    public:
        GraphicsVisible(const eTexture texture_id);
        virtual ~GraphicsVisible();
        virtual void Update(GameObject* object, Engine& engine);
    protected:
    private:
        eTexture texture_id_;
};

#endif // VISIBLEGRAPHICS_H
