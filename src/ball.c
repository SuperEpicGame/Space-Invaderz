#include <SDL3/SDL.h>
#include "collision.h"

SDL_FRect ball = {470, 370, 30, 30};

void renderBall(SDL_Renderer *renderer)
{
    SDL_RenderFillRect(renderer, &ball);
}

void moveBall()
{
    ball.x += ballVelX;
    ball.y += ballVelY;
}