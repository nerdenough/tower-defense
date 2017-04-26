#include "texture.h"

Texture::Texture(SDL_Renderer *renderer) {
  this->renderer = renderer;
  texture = NULL;
  width = 0;
  height = 0;
}

Texture::~Texture() {
  free();
}

bool Texture::loadFromFile(std::string path) {
  free();

  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    printf("Error loading surface: %s\n", IMG_GetError());
    return false;
  }

  texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if (texture == NULL) {
    printf("Error creating texture: %s\n", SDL_GetError());
    return false;
  }

  width = loadedSurface->w;
  height = loadedSurface->h;
  SDL_FreeSurface(loadedSurface);

  return true;
}

void Texture::free() {
  if (texture == NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

void Texture::render(int x, int y, SDL_Rect *clip) {
  SDL_Rect renderQuad = { x, y, width, height };

  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

int Texture::getWidth() {
  return width;
}

int Texture::getHeight() {
  return height;
}
