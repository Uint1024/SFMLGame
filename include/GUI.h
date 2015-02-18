/* 
 * File:   GUI.h
 * Author: John
 *
 * Created on 17 février 2015, 00:05
 */

#ifndef GUI_H
#define	GUI_H
#include <SFML/System/Vector2.hpp>
#include "Bbox.h"

class InputManager;
class Engine;
class GUI{
public:
    
    GUI(const sf::Vector2f& position, const sf::Vector2f& size);
    virtual void Render(Engine& engine) = 0;
    virtual void Move(const sf::Vector2f& movement);
    virtual void Update(Engine& engine, InputManager& input_manager) = 0;
    virtual void TestFunction();
    virtual void ClickedOnChild(const int type, const int subtype) = 0;
    const Bbox& GetBbox() const{
        return bbox_;
    }
protected:
    Bbox bbox_;  
    sf::Vector2f position_;
};

#endif	/* GUI_H */

