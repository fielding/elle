//
//  Position.h
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Position__
#define __elle__Position__

#include "IComponent.h"

class Position: public IComponent
{
public:
  Position(int x, int y, int width, int height, bool wrap_around = false,
           int boundary_height = 576, int boundary_width = 1024,
           int boundary_top = -16, int boundary_left = -16)
  : x(x), y(y),
    width(width), height(height),
    wrap_around(wrap_around),
    boundary_height(boundary_height), boundary_width(boundary_width),
    boundary_top(boundary_top), boundary_left(boundary_left),
    prev_x(x), pprev_x(x),
    prev_y(y), pprev_y(y) { }
  
  ~Position() { }
  
  int x;
  int y;
  
  int prev_x;
  int prev_y;
  
  int pprev_x;
  int pprev_y;
  
  int next_x;
  int next_y;
  
  int width;
  int height;
  
  int boundary_top;
  int boundary_left;
  int boundary_height;
  int boundary_width;

  bool wrap_around;
  
};

#endif /* defined(__elle__Position__) */

