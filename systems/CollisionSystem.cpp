//
//  CollisionSystem.cpp
//  elle
//
//  Created by Fielding Johnston on 6/10/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#include "CollisionSystem.h"

using namespace std;

CollisionSystem::CollisionSystem(vector<Entity> *entities, Game *game)
{
  cerr << "CollisionSystem Initialized" << endl;
  this->entities = entities;
  this->game = game;
}

CollisionSystem::~CollisionSystem()
{
  cerr << "CollisionSystem Deinitialized" <<endl;
}

void CollisionSystem::process(float dt)
{

  // REFACTOR: Get current collidable entities
  vector<Entity> collidables;
  for(vector<Entity>::iterator it = entities->begin(); it != entities->end(); ++it)
  {
    if (it->components.count(&typeid(Collidable)) && it->components.count(&typeid(Position)))
    {
      Position *position = it->getComponent<Position>();
      Collidable *collidable = it->getComponent<Collidable>();

      collidable->body.top = position->y;
      collidable->body.left = position->x;
      collidable->body.height = position->height;
      collidable->body.width = position->width;

      collidables.push_back(*it);
    }
  }

  for(vector<Entity>::iterator it = collidables.begin(); it != collidables.end(); ++it)
  {
    for(vector<Entity>::iterator it2 = it + 1; it2 != collidables.end(); ++it2)
    {
      if (it->getComponent<Collidable>()->body.intersects(it2->getComponent<Collidable>()->body))
      {
        // TODO: Need to figure out a way to abstract this out, so each game
        // can customize the behaviours of different entities when they collide.

        // COLLISION TYPE: example using tail and food from a snake game
        // if (it->getComponent<Food>() && it2->getComponent<Tail>())
        // {
        //   Food *food = it->getComponent<Food>();
        //   Tail *tail = it2->getComponent<Tail>();
        //   food->eaten = true;
        //   tail->segment_count = tail->segment_count + 3;
        // }
        // else if (it2->getComponent<Food>() && it->getComponent<Tail>())
        // {
        //   Tail *tail = it->getComponent<Tail>();
        //   Food *food = it2->getComponent<Food>();
        //   food->eaten = true;
        //   tail->segment_count = tail->segment_count + 3;
        // }
        // else if (it->getComponent<Tail>() && it2->getComponent<Segment>())
        // {
        //   Position *head_position = it->getComponent<Position>();
        //   Position *segment_position = it2->getComponent<Position>();
        //
        //   cerr << "Collision Detected!" << endl;
        //   cerr << "Head piece at: " << head_position->x << ", "<< head_position->y << endl;
        //   cerr << "Tail piece at: " << segment_position->x << ", "<< segment_position->y << endl;
        //
        //   game->gameOver();
        // }
        // else if (it->getComponent<Segment>() && it2->getComponent<Tail>())
        // {
        //   Position *segment_position = it->getComponent<Position>();
        //   Position *head_position = it2->getComponent<Position>();
        //
        //   cerr << "Collision Detected!" << endl;
        //   cerr << "Head piece at: " << head_position->x << ", "<< head_position->y << endl;
        //   cerr << "Tail piece at: " << segment_position->x << ", "<< segment_position->y << endl;
        //
        //   game->gameOver();
        // }
        //
        // Collision Type: Player and Player(tail)

      }
    }
  }

  collidables.clear();
}

