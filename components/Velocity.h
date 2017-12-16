//
//  Velocity.h
//  elle
//
//  Created by Fielding Johnston on 6/7/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Velocity__
#define __elle__Velocity__

#include "IComponent.h"

class Velocity: public IComponent
{
public:
  Velocity(float x, float y)
  : xVel(x), yVel(y),
    prev_xVel(x), prev_yVel(y) { }
  
  ~Velocity() { }

  float xVel;
  float yVel;
  float prev_xVel;
  float prev_yVel;
};

#endif /* defined(__elle__Velocity__) */

