#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "src/player.h"
#include "src/ball.h"

int main(int argc, char *argv[])
{

    SDL_Window *window = SDL_CreateWindow("Pong", 1000, 800, 0); // Skapar mitt fönster. Namn, bredd, höjd, flaggor.
    SDL_ShowWindow(window);                                      // Visa mitt fönster
    SDL_Event buttonPressed;
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, 0);

    // SDL_SetWindowIcon();
    while (1)
    {
        while (SDL_PollEvent(&buttonPressed)) // Pollad lösning: har något hänt?
        {
            if (buttonPressed.type == SDL_EVENT_QUIT) // Trycker användaren på x
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window); // Stäng fönster
                SDL_Quit();                // Stäng program
                return 0;
            }
        }
        const bool *keystate = SDL_GetKeyboardState(NULL);      //Läsa in alla knapptryck "samtidigt". Så att båda spelarna kan röra sig samtidigt.
        if (keystate[SDL_SCANCODE_W])
        {
            movePlayer1(-5); // Upp p1
        }
        if (keystate[SDL_SCANCODE_S])
        {
            movePlayer1(5); // Ner p1
        }
        if (keystate[SDL_SCANCODE_UP])
        {
            movePlayer2(-5); // Upp p2
        }
        if (keystate[SDL_SCANCODE_DOWN])
        {
            movePlayer2(5); // Ner p2
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // set color to white
        SDL_RenderClear(renderer);                            // White background

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // set color to red
        renderPlayer1(renderer);                          // Red block
        renderPlayer2(renderer);                          // Red block
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // set color to black
        renderBall(renderer);                             // black ball
        SDL_RenderPresent(renderer);                      // Present frame

        SDL_Delay(16); // Så att det inte går för snabbt
    }
}
