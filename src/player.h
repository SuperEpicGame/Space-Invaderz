#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

extern SDL_FRect rectangle1, rectangle2;

void renderPlayer1(SDL_Renderer * renderer);
void renderPlayer2(SDL_Renderer * renderer);
void movePlayer1(float dy);
void movePlayer2(float dy);


#endif