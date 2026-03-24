#include <SDL3/SDL.h>
#include "collision.h"

SDL_FRect ball = {470, 370, 30, 30};

void renderBall(SDL_Renderer *renderer)
{
    SDL_RenderFillRect(renderer, &ball);
}
int p1Points = 0;
int p2Points = 0;

void moveBall()
{

    if (ball.x < 0)
    {
        p2Points++;
        ballVelY = 1.0f;
        ballVelX = 5.0f;
        ball.x = 470;
        ball.y = 370;
    }
    if (ball.x > 1000)
    {
        p1Points++;
        ballVelY = 1.0f;
        ballVelX = -5.0f;
        ball.x = 470;
        ball.y = 370;
    }

    ball.x += ballVelX;
    ball.y += ballVelY;

    if (ball.y < 0)
    {
        ball.y = 0;
        ballVelY = -ballVelY;     //Byt håll
    }
    if (ball.y > 800 - ball.h) //Max - height för att stoppa att åka igenom.
    {
        ball.y = 800 - ball.h;
        ballVelY = -ballVelY;     //Byt håll
    }
}