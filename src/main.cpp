#include <iostream>
#include "game.hpp"

/**
 * @file main.cpp
 */

int main(void) {

  // instantiate a new Game:
  Game game(800, 600, 32.f);

  // main game loop:
  while (game.running()) {
    game.update();
    game.render();
  }
  
  return 0;
}
