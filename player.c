#include <SDL3/SDL.h>

SDL_FRect rectangle1 = {20, 300, 20, 200};
SDL_FRect rectangle2 = {960, 300, 20, 200};

void renderPlayer(SDL_Renderer * renderer) {
    SDL_RenderRect(renderer,&rectangle1);
    SDL_RenderRect(renderer,&rectangle2);
}