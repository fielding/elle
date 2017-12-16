//
//  MovementSystem.cpp
//  elle
//
//  Created by Fielding Johnston on 6/7/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#include "MovementSystem.h"

using namespace std;

MovementSystem::MovementSystem(std::vector<Entity> *entities)
{
  cerr << "MovementSystem Initialized" << endl;
  this->entities = entities;
}

MovementSystem::~MovementSystem()
{
    cerr << "MovementSystem Deinitialized" << endl;
}

void MovementSystem::process(float dt)
{
  for(std::vector<Entity>::iterator it = entities->begin(); it != entities->end(); ++it)
  {
    if ( it->components.count(&typeid(Velocity)) && it->components.count(&typeid(Position)) && it->components.count(&typeid(Segment)) == 0)
    {
      Velocity *velocity = it->getComponent<Velocity>();
      Position *position = it->getComponent<Position>();
      
      position->pprev_x = position->prev_x;
      position->pprev_y = position->prev_y;
      
      position->prev_y = position->y;
      position->prev_x = position->x;
      
      position->x += velocity->xVel;
      position->y += velocity->yVel;
      
      if (position->x < position->boundary_left)
      {
        if (position->wrap_around == true)
        {
          position->prev_x = position->boundary_width;
          position->x = position->boundary_width;
        }
        else
          position->x = position->boundary_left;
      }
      
      if (position->x > position->boundary_width)
      {
        if (position->wrap_around == true)
        {
          position->prev_x = position->boundary_left;
          position->x = position->boundary_left;
        }
        else
          position->x = position->boundary_width;
      }
      
      if (position->y < position->boundary_top)
      {
        if (position->wrap_around == true)
        {
          position->prev_y = position->boundary_height;
          position->y = position->boundary_height;
        }
        else
          position->y = position->boundary_top;
      }
      
      if (position->y > position->boundary_height)
      {
        if (position->wrap_around == true)
        {
          position->prev_y = position->boundary_top;
          position->y = position->boundary_top;
        }
        else
          position->y = position->boundary_height;
      }
    }
  }
}

