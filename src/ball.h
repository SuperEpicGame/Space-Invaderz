#ifndef BALL_H
#define BALL_H

#include <SDL3/SDL.h>

extern SDL_FRect ball;

void renderBall(SDL_Renderer * renderer);
void moveBall();
// void moveBallInit();

#endif