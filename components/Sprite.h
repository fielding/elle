//
//  Sprite.h
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Sprite__
#define __elle__Sprite__

#include "IComponent.h"

class Sprite: public IComponent
{
public:
  Sprite(std::string image_path)
   : image_path(image_path) { }
  
  ~Sprite() { }
  
  std::string image_path;
};

#endif /* defined(__elle__Sprite__) */

