//
//  CollisionSystem.h
//  elle
//
//  Created by Fielding Johnston on 6/10/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__CollisionSystem__
#define __elle__CollisionSystem__

#include "../ISystem.h"
#include "../Game.h"
#include "../components/Collidable.h"
#include "../components/Position.h"

class Game;

class CollisionSystem: public ISystem
{
public:
  CollisionSystem(std::vector<Entity> *entities, Game *game);
  ~CollisionSystem();
  void process(float dt);

  Game *game;
};

#endif /* defined(__elle__CollisionSystem__) */

