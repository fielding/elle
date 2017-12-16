//
//  PlayerControlSystem.cpp
//  elle
//
//  Created by Fielding Johnston on 6/7/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#include "PlayerControlSystem.h"

using namespace std;

PlayerControlSystem::PlayerControlSystem(std::vector<Entity> *entities)
{
  cerr<< "PlayerControlSystem Initialized" <<endl;
  this->entities = entities;
  this->queued_move = 0;
}

PlayerControlSystem::~PlayerControlSystem()
{
  cerr<< "PlayerControlSystem Deinitialized" <<endl;
}

void PlayerControlSystem::process(float dt)
{
  double vel = 8;
  
  for(std::vector<Entity>::iterator it = entities->begin(); it != entities->end(); ++it)
  {    
    if( it->components.count(&typeid(PlayerControl)) && it->components.count(&typeid(Position)) && it->components.count(&typeid(Velocity)))
    {
      Velocity *velocity = it->getComponent<Velocity>();
      Position *position = it->getComponent<Position>();
      if ( queued_move == 0 )
      {
        velocity->prev_xVel = velocity->xVel;
        velocity->prev_yVel = velocity->yVel;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && velocity->yVel <= 0)
        {
          if ( position->x % 16 == 0)
          {
            velocity->yVel = -vel;
            velocity->xVel = 0;
          }
          else
          {
            queued_move = 1;
          }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && velocity->yVel >= 0)
        {
          if ( position->x % 16 == 0)
          {
            velocity->yVel = vel;
            velocity->xVel = 0;
          }
          else
          {
            queued_move = 2;
          }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && velocity->xVel <= 0)
        {
          if ( position->y % 16 == 0)
          {
            velocity->yVel = 0;
            velocity->xVel = -vel;
          }
          else
          {
            queued_move = 3;
          }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && velocity->xVel >= 0)
        {
          if ( position->y % 16 == 0)
          {
            velocity->yVel = 0;
            velocity->xVel = vel;
          }
          else
          {
            queued_move = 4;
          }
        }
      }
      else
      {
        if ( position->x % 16 == 0 && position->y % 16 == 0)
        {
            switch( queued_move )
            {
              case 1:
                velocity->yVel = -vel;
                velocity->xVel = 0;
                break;
              case 2:
                velocity->yVel = vel;
                velocity->xVel = 0;
                break;
              case 3:
                velocity->yVel = 0;
                velocity->xVel = -vel;
                break;
              case 4:
                velocity->yVel = 0;
                velocity->xVel = vel;
                break;
            }
            queued_move = 0;
        }
      }
    }
  }
}
