//
//  RenderSystem.h
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__RenderSystem__
#define __elle__RenderSystem__

#include <SFML/Graphics.hpp>

#include "../ISystem.h"
#include "../components/Sprite.h"
#include "../components/Position.h"
#include "../components/Velocity.h"
#include "../components/RectangleShape.h"

class RenderSystem: public ISystem
{
public:
  RenderSystem(std::vector<Entity> *entities, sf::RenderWindow* window);
  ~RenderSystem();
  void process(float dt);

private:
  sf::RenderWindow* window;
};

#endif /* defined(__elle__RenderSystem__) */

