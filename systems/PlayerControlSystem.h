//
//  PlayerControlSystem.h
//  elle
//
//  Created by Fielding Johnston on 6/7/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__PlayerControlSystem__
#define __elle__PlayerControlSystem__

#include <SFML/Graphics.hpp>

#include "../ISystem.h"
#include "../components/Position.h"
#include "../components/Velocity.h"
#include "../components/PlayerControl.h"

class PlayerControlSystem: public ISystem
{
public:
  PlayerControlSystem(std::vector<Entity> *entities);
  ~PlayerControlSystem();
  void process(float dt);

  int queued_move;
};

#endif /* defined(__elle__PlayerControlSystem__) */

