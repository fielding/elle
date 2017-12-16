//
//  Game.h
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#ifndef __elle__Game__
#define __elle__Game__

#include <vector>
#include <list>
#include <typeinfo>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

// Core
#include "common.h"
#include "Entity.h"
#include "IComponent.h"
#include "ISystem.h"

// Components
#include "components/Position.h"
#include "components/Sprite.h"
#include "components/Velocity.h"
#include "components/PlayerControl.h"
#include "components/Collidable.h"
#include "components/RectangleShape.h"

// Systems
#include "systems/RenderSystem.h"
#include "systems/PlayerControlSystem.h"
#include "systems/MovementSystem.h"
#include "systems/CollisionSystem.h"

class Game
{
public:
  Game(const char* title, int width=640, int height=480, int top_boundary = 0,
       int left_boundary = 0, int bottom_boundary = 480, int right_boundary = 640,
       int max_frameskip = 5, double skip_ticks = 33.3333);
  ~Game();

  void run();

  void handleInterfaceInput();
  Entity* addEntity();


  bool isRunning();
  void quit();
  void gameOver();

  int max_frameskip;
  double skip_ticks;

  sf::Clock global_clock;
  sf::RenderWindow window;
  sf::Event event;

  std::vector<Entity> entities;
  std::vector<ISystem*> systems;
  RenderSystem *render_system;

private:
  bool running;
};

#endif /* defined(__elle__Game__) */

