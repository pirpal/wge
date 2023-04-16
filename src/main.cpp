#include <iostream>
#include "game.hpp"

int main(void) {

  // instantiate a new Game:
  Game game(600, 400);

  // main game loop:
  while (game.running()) {
    game.update();
    game.render();
  }
  
  return 0;
}
