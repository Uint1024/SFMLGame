/* 
 * File:   Message.h
 * Author: John
 *
 * Created on 14 février 2015, 00:08
 */

#ifndef MESSAGE_H
#define	MESSAGE_H
#include "Globals.h"
class GameObject;

struct Message {
    GameObject* sender;
    eMsg message_id;
    int integer;
    float floating_point;
};

#endif	/* MESSAGE_H */

