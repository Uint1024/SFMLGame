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
    int path_;
    int previous_node_;
    int next_node_;
    const float speed_ = 300;
    bool go_in_reverse_;
    bool angry_;
    float fov_;
    float havent_seen_player_for_;
};

#endif	/* CONTROLSAI_H */

