#include <SDL2/SDL.h>
#include <stdio.h>
#include "game/game.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char *args[]) {
  Game *game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

  if (!game->init()) {
    printf("Initialise failed!\n");
    return 0;
  }

  game->gameloop();
  game->close();

  return 0;
}
