#include <SDL2/SDL.h>
#include "../texture/texture.h"

class PlayState {
  public:
    PlayState();
    ~PlayState();
    void init(SDL_Renderer *renderer);
    void update(float dt);
    void render();
  private:
    Texture *texture;
    float stickX;
    float stickY;
};
