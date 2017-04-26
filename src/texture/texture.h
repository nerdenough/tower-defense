#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

class Texture {
  public:
    Texture();
    ~Texture();
    bool loadFromFile(std::string path, SDL_Renderer *renderer);
    void free();
    void render(int x, int y, SDL_Rect *clip = NULL);
    int getWidth();
    int getHeight();
  private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int width;
    int height;
};
