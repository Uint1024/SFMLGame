/* 
 * File:   LevelEditorWindow.h
 * Author: John
 *
 * Created on 16 février 2015, 01:52
 */

#ifndef LEVELEDITORWINDOW_H
#define	LEVELEDITORWINDOW_H
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include "Globals.h"
#include "Bbox.h"
#include "GameObject.h"


class Engine;
//GUI inherits from gameobject????
class LevelEditorWindow : public GameObject{
public:
    LevelEditorWindow(const sf::Vector2f& position);
    virtual ~LevelEditorWindow();
    //TODO: read listeners tutorial
    //TODO: read GUI tutorial
private:
    bool displayed_;

};

#endif	/* LEVELEDITORWINDOW_H */

