//
//  RenderSystem.cpp
//  elle
//
//  Created by Fielding Johnston on 6/6/13.
//  Copyright (c) 2013 Fielding Johnston. All rights reserved.
//

#include "RenderSystem.h"

using namespace std;

RenderSystem::RenderSystem(vector<Entity> *entities, sf::RenderWindow* window)
{
  cerr << "RenderSystem Initialized" << endl;
  this->entities = entities;
  this->window = window;
}


RenderSystem::~RenderSystem()
{
  cerr<< "RenderSystem Deinitialized" <<endl;
}

void RenderSystem::process(float dt)
{
  float render_pos_x, render_pos_y;
  // clear the screen
  window->clear();
  
  for(std::vector<Entity>::iterator it = entities->begin(); it != entities->end(); ++it)
  {
    
    // Draw entities with Sprite Component and Position Component
    if( it->components.count(&typeid(Sprite)) && it->components.count(&typeid(Position)))
    {
      Sprite *sprite = it->getComponent<Sprite>();
      Position *position = it->getComponent<Position>();
      
      sf::Texture texture;
      if (!texture.loadFromFile(sprite->image_path)) {
        cerr << "Couldn't load image" << sprite->image_path << endl;
      }
      
      // create a sprite using that texture
      sf::Sprite sprite_component(texture);
      
      // REVIEW: Figure out best way to handle interpolation and smoothing
      
      if ( it->components.count(&typeid(Velocity)))
      {
        Velocity *velocity = it->getComponent<Velocity>();
        
        render_pos_x = position->x + (velocity->xVel * dt);
        render_pos_y = position->y + (velocity->yVel * dt);
      }
      else
      {
        render_pos_x = position->x;
        render_pos_y = position->y;
      }
  
      sprite_component.setPosition(render_pos_x, render_pos_y);
      
      window->draw(sprite_component);
    }
    
    // Draw entities with RectangleShape Component and Position Component
    if ( it->components.count(&typeid(RectangleShape)) && it->components.count(&typeid(Position)) )
    {
      Position *position = it->getComponent<Position>();
      RectangleShape *rectangle = it->getComponent<RectangleShape>();
      
      sf::RectangleShape sf_rect;
      sf::Color color(rectangle->red, rectangle->green, rectangle->blue, rectangle->alpha);
    
      
      render_pos_x = position->x + ((position->next_x - position->x) * dt);
      render_pos_y = position->y + ((position->next_y - position->y) * dt);
      
      // special cases for wrap around
      if ( position->wrap_around == true )
      {
          if ( position->next_x == position->boundary_left )
            render_pos_x = position->x;
        
          if ( position->next_x == position->boundary_width )
            render_pos_x = position->x;
        
          if ( position->next_y == position->boundary_top )
            render_pos_y = position->y;
        
          if ( position->next_y == position->boundary_height )
            render_pos_y = position->y;
      }
      
      sf_rect.setSize(sf::Vector2f(position->height, position->width));
      sf_rect.setPosition(render_pos_x, render_pos_y);
      sf_rect.setFillColor(color);
      
      window->draw(sf_rect);
      
    }
  }
  
  
  // update the window
  window->display();
}

