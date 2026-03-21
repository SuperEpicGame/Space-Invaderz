#include <SDL3/SDL.h>

SDL_FRect rectangle1 = {20, 300, 20, 200};
SDL_FRect rectangle2 = {960, 300, 20, 200};

void renderPlayer1(SDL_Renderer * renderer) {
    SDL_RenderFillRect(renderer,&rectangle1);
}
void renderPlayer2(SDL_Renderer * renderer) {
    SDL_RenderFillRect(renderer,&rectangle2);
}

void movePlayer1(float dy)
{
    rectangle1.y += dy;

    if (rectangle1.y < 0)
    {
        rectangle1.y = 0;
    }
    if (rectangle1.y > 800 - rectangle1.h) //Max - height för att stoppa att åka igenom.
    {
        rectangle1.y = 800 - rectangle1.h;
    }
    
}
void movePlayer2(float dy)
{
    rectangle2.y += dy;

    if (rectangle2.y < 0)
    {
        rectangle2.y = 0;
    }
    if (rectangle2.y > 800 - rectangle2.h) //Max - height för att stoppa att åka igenom.
    {
        rectangle2.y = 800 - rectangle2.h;
    }
}