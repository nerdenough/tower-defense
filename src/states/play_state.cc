#include "play_state.h"

PlayState::PlayState() {
  texture = new Texture();
}

PlayState::~PlayState() {
  texture->free();
}

void PlayState::init(SDL_Renderer *renderer) {
  texture->loadFromFile("assets/stick_figure.png", renderer);
}

void PlayState::update(float dt) {

}

void PlayState::render() {
  texture->render(0, 0);
}
