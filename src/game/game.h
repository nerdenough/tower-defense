#include <SDL2/SDL.h>
#include "../states/play_state.h"

class Game {
  public:
    Game(int screenWidth, int screenHeight);
    bool init();
    void update(float dt);
    void render();
    void gameloop();
    void close();
  private:
    int screenWidth;
    int screenHeight;
    SDL_Window *window;
    SDL_Renderer *renderer;
    PlayState playState;
};
