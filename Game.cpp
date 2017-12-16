//
//  Game.cpp
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#include "Game.h"

using namespace std;

Game::Game(const char* title, int width, int height, int top_boundary,
           int left_boundary, int bottom_boundary,
           int right_boundary, int max_frameskip,
           double skip_ticks) : window(sf::VideoMode(width, height), title)
{
  running = true;
  this->max_frameskip = max_frameskip;
  this->skip_ticks = skip_ticks;
  
  // Initialize core systems
  systems.push_back(new PlayerControlSystem(&entities));
  systems.push_back(new MovementSystem(&entities));
  systems.push_back(new CollisionSystem(&entities, this));
  
  // Keep render system seperate for independent update/fps game loop
  render_system = new RenderSystem(&entities, &window);
}

Game::~Game()
{
  
}

void Game::run()
{
  unsigned int next_game_tick, loops;
  
  next_game_tick = global_clock.getElapsedTime().asMilliseconds();
  
  while ( isRunning() )
  {
    loops = 0;
    
    while ( global_clock.getElapsedTime().asMilliseconds() > next_game_tick
           && loops < max_frameskip)
    {
      
      handleInterfaceInput();
  
      for ( vector<ISystem*>::iterator it = systems.begin(); it != systems.end(); ++it )
      {
        (*it)->process(skip_ticks);
      }
      
      next_game_tick += skip_ticks;
      loops++;
    }
    
    render_system->process(float(global_clock.getElapsedTime().asMilliseconds() + skip_ticks - next_game_tick) / float(skip_ticks) );
  }
}

void Game::handleInterfaceInput()
{
  while (window.pollEvent(event))
  {
    // Close window : exit
    if (event.type == sf::Event::Closed)
      quit();
    
    // Espace pressed : exit
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
      quit();
  }
}

Entity* Game::addEntity()
{
  entities.push_back(*new Entity);
  return &(*entities.end());
}

bool Game::isRunning()
{
  return running;
}

void Game::quit()
{
  running = false;
  window.close();
}

void Game::gameOver()
{
  running = false;
}

