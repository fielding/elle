//
//  Collidable.h
//  elle
//
//  Created by Fielding Johnston on 6/10/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Collidable__
#define __elle__Collidable__

#include <SFML/Graphics.hpp>
#include "IComponent.h"

class Collidable: public IComponent
{
public:
  Collidable() { }
  
  Collidable(sf::FloatRect body)
  : body(body) { }
  
  ~Collidable() { }

  sf::FloatRect body;
};

#endif /* defined(__elle__Collidable__) */

