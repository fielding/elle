//
//  RectangleShape.h
//  elle
//
//  Created by Fielding Johnston on 6/11/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__RectangleShape__
#define __elle__RectangleShape__

#include "IComponent.h"

class RectangleShape: public IComponent
{
public:
  RectangleShape(int red, int green, int blue, int alpha)
  : red(red), green(green),
    blue(blue), alpha(alpha) { }
  
  ~RectangleShape() { }

  int red;
  int green;
  int blue;
  int alpha;
};

#endif /* defined(__elle__RectangleShape__) */

