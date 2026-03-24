#include <SDL3/SDL.h>
#include <math.h>
#include "ball.h"
#include "player.h"

float ballVelX = 4.0f; //hastighet
float ballVelY = 0.0f;
int startCounter = 0;

void checkCollision()
{
   
    if (ballVelX < 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle1))   //Har bollen träffat p1?
    {
        startCounter = 1;
        ballVelX = -ballVelX;           //bounce right
        
    }

    else if (ballVelX > 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle2))   //Har bollen träffat p2?
    {
        startCounter = 1;
        ballVelX = -ballVelX;           //bounce left
    }
}
