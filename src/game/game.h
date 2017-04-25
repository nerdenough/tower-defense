#include <SDL2/SDL.h>

class Game {
  public:
    Game(int screenWidth, int screenHeight);
    ~Game();
    bool init();
    void update();
    void render();
    void gameloop();
    void close();
  private:
    int screenWidth;
    int screenHeight;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
