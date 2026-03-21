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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bakgrundsfärg
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Röd färg på spelblocken
    renderPlayer1(renderer);
    renderPlayer2(renderer);

    renderBall(renderer);

    SDL_RenderPresent(renderer); // Visa allt på skärmen. Typ som ecall.

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
            if (buttonPressed.type == SDL_EVENT_KEY_DOWN) // When key is pressed:
            {
                switch (buttonPressed.key.key)
                {
                    case SDLK_W:
                    {
                        movePlayer1(-5);
                        // Move up. y--
                        break;
                    }
                    case SDLK_S:
                    {
                        movePlayer1(5);
                        // Move down. y++
                        break;
                    }
                    default:
                    {
                    break;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   //set color to white 
        SDL_RenderClear(renderer);                              //White background

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);       //set color to red
        renderPlayer1(renderer);                                //Red block
        renderPlayer2(renderer);                                //Red block
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);         //set color to black    
        renderBall(renderer);                                   //black ball
        SDL_RenderPresent(renderer);                            //Present frame
    }
}
