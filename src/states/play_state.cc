#include "play_state.h"

PlayState::PlayState() {
  texture = new Texture();
  stickX = 0;
  stickY = 0;
}

PlayState::~PlayState() {
  texture->free();
}

void PlayState::init(SDL_Renderer *renderer) {
  texture->loadFromFile("assets/stick_figure.png", renderer);
}

void PlayState::update(float dt) {
  stickX += 100 * dt;
  stickY += 100 * dt;
}

void PlayState::render() {
  texture->render((int) stickX, (int) stickY);
}
