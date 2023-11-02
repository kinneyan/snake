#ifndef MAIN_H
#define MAIN_H

#include "SDL2/SDL.h"
#include "game.hpp"

class App
{
private:
    SDL_Window* window;
    bool exitNow = false;

    void cleanup()
    {
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

public:
    App()
    {
        // intialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
            exit(1);
        }

        this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->window == NULL)
        {
            std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    void run();

};

#endif
