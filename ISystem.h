//
//  ISystem.h
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef elle_ISystem_h
#define elle_ISystem_h

#include "Entity.h"
#include <string>
#include <vector>
#include <iostream>

class ISystem
{
public:
  virtual ~ISystem() {}
  virtual void process(float dt) = 0;
protected:
  std::vector<Entity> *entities;
};

#endif

