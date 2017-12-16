//
//  MovementSystem.h
//  elle
//
//  Created by Fielding Johnston on 6/7/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__MovementSystem__
#define __elle__MovementSystem__

#include "../ISystem.h"
#include "../components/Velocity.h"
#include "../components/Position.h"

class MovementSystem: public ISystem
{
public:
  MovementSystem(std::vector<Entity> *entities);
  ~MovementSystem();
  void process(float dt);
};

#endif /* defined(__elle__MoveSystem__) */

