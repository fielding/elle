#include <iostream>

#include "Game.h"
#include "configure.h"

//
// Include any game specific components/systems
//
// Components
#include "CustomComponent.h"
// Systems
#include "CustomSystem.h"

using namespace std;

int main(int argc, char **argv)
{
  // TODO: Consider best options for passing configuration to game object
  Game example("example game", SCREEN_WIDTH, SCREEN_HEIGHT, TOP_BOUNDARY,
              LEFT_BOUNDARY, BOTTOM_BOUNDARY, RIGHT_BOUNDARY);

  // Initialize any Game specific systems
  example.systems.push_back(new CustomSystem(&example.entities));

  Entity player;
  player.addComponent(new Sprite(resourcePath() + "player.png"));
  player.addComponent(new Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 , 16, 16, true));
  player.addComponent(new Velocity(8, 0));
  player.addComponent(new PlayerControl);
  player.addComponent(new Collidable);
  player.addComponent(new CustomComponent);
  example.entities.push_back(player);

  Entity object;
  object.addComponent(new Sprite(resourcePath() + "object.png"));
  object.addComponent(new Position(-50, -50, 16, 16));
  object.addComponent(new Collidable);
  example.entities.push_back(object);

  example.run();

  return 0;
}
