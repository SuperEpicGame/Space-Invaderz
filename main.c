#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "src/player.h"
#include "src/ball.h"
#include "src/collision.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Window *window = SDL_CreateWindow("Pong", 1000, 800, 0); // Skapar mitt fönster. Namn, bredd, höjd, flaggor.
    SDL_ShowWindow(window);                  // Visa mitt fönster
    SDL_Gamepad *gamePad;                              
    SDL_Event buttonPressed;
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, 0);
    
    int count[10] = {0};
    SDL_GetGamepads(count);
    gamePad = SDL_OpenGamepad(count[0]);
    SDL_RumbleGamepad(gamePad, 0x0FFF, 0xFF00, 2000);
    int startCounter = 0;

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
        const bool *keystate = SDL_GetKeyboardState(NULL); // Läsa in alla knapptryck "samtidigt". Så att båda spelarna kan röra sig samtidigt.

        if (keystate[SDL_SCANCODE_W] || SDL_GetGamepadButton(gamePad, SDL_GAMEPAD_BUTTON_DPAD_UP))
        {
            movePlayer1(-5); // Upp p1
        }
        if (keystate[SDL_SCANCODE_S] || SDL_GetGamepadButton(gamePad, SDL_GAMEPAD_BUTTON_DPAD_DOWN))
        {
            movePlayer1(5); // Ner p1
        }
        if (keystate[SDL_SCANCODE_UP] || SDL_GetGamepadButton(gamePad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT))
        {
            movePlayer2(-5); // Upp p2
        }
        if (keystate[SDL_SCANCODE_DOWN] || SDL_GetGamepadButton(gamePad, SDL_GAMEPAD_BUTTON_DPAD_LEFT))
        {
            movePlayer2(5); // Ner p2
        }

        if (startCounter == 0)
        {
            ballVelX = -5.0f;
            ballVelY = 0.0f;
            startCounter = 1;
        }
        else
        {
            moveBall();
        }
        checkCollision();


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // set color to white
        SDL_RenderClear(renderer);                            // White background
        


        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // set color to red
        SDL_RenderDebugTextFormat(renderer, 480, 20,"p1:%d  p2:%d", p1Points,p2Points); //Skriv ut poängen.
        renderPlayer1(renderer);                          // Red block
        renderPlayer2(renderer);                          // Red block
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // set color to black
        renderBall(renderer);                             // black ball

        
        if(p1Points >= 5)
        {
            //SDL_RenderDebugText(renderer,500,400,"Winner: %d");
            SDL_RenderDebugTextFormat(renderer,500,400,"The winner is: P1 with: %d points", p1Points);
            SDL_RenderPresent(renderer);
            SDL_Delay(1800);
            break;
        }
        if(p2Points >= 5)
        {
            SDL_RenderDebugTextFormat(renderer,500,400,"The winner is: P2 with: %d points", p2Points);
            SDL_RenderPresent(renderer);
            SDL_Delay(1800);
            break;
        }

        SDL_RenderPresent(renderer);                      // Present frame

        SDL_Delay(16); // Så att det inte går för snabbt
    }
}
