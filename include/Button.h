/* 
 * File:   Button.h
 * Author: John
 *
 * Created on 17 février 2015, 00:11
 */

#ifndef BUTTON_H
#define	BUTTON_H

enum eButton{
    Object
};

class Button {
public:
    Button();
    virtual ~Button();
    
private:
    //eButton button_type;
    int subtype; //object type in case of object button, etc.
};

#endif	/* BUTTON_H */

