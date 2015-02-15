/* 
 * File:   ControlsAI.h
 * Author: John
 *
 * Created on 13 février 2015, 04:24
 */

#ifndef CONTROLSAI_H
#define	CONTROLSAI_H

#include "ControlsComponent.h"


class ControlsAI : public ControlsComponent{
public:
  ControlsAI();
  virtual ~ControlsAI();
  virtual void Update(GameObject* object, Engine& engine,
                            GameData& game_data);
private:

};

#endif	/* CONTROLSAI_H */

