#include "game.h"

Game::Game(int screenWidth, int screenHeight) {
  this->screenWidth = screenWidth;
  this->screenHeight = screenHeight;
}

Game::~Game() {
  close();
}

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL failed to initialise! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("Tower Defense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void Game::close() {
  SDL_DestroyRenderer(renderer);
  renderer = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}

void Game::update(float dt) {
  printf("Update! dt: %f\n", dt);
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
}

void Game::gameloop() {
  bool running = true;
  SDL_Event e;
  Uint32 currentTicks = SDL_GetTicks();

  while (running) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        running = false;
      }
    }

    Uint32 newTicks = SDL_GetTicks();
    float dt = (newTicks - currentTicks) / 1000.f;
    currentTicks = newTicks;

    update(dt);
    render();
  }
}
