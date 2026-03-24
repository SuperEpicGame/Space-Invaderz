#include <SDL3/SDL.h>
#include <math.h>
#include "ball.h"
#include "player.h"

float ballVelX = 2.0f; // speed per frame
float ballVelY = 0.0f;
int startCounter = 0;

void checkCollision()
{
   
    // Left paddle
    if (ballVelX < 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle1))
    {
        startCounter = 1;
        ball.x = rectangle1.x + rectangle1.w; // push ball outside paddle
        ballVelX = -ballVelX;                 // bounce right
    }

    // Right paddle
    else if (ballVelX > 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle2))
    {
        startCounter = 1;
        ball.x = rectangle2.x - ball.w; // push ball outside paddle
        ballVelX = -ballVelX;           // bounce left
    }
}