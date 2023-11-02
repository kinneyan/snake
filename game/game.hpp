#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include "SDL2/SDL.h"
#include "block.hpp"
#include "snake.hpp"
#include "apple.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define GAME_TIME 64

class Game
{

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    bool exitNow = false;

    Snake snake;
    Apple apple;
    int score = 0;
    float difficultyMult = 1;

    void close()
    {
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    void getInput();
    void checkRules();
    void gameLoop();

public:
    Game()
    {
        // intialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "Failed to initialize SDL: ", SDL_GetError();
            exit(1);
        }

        this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->window == NULL)
        {
            std::cout << "Failed to create window: ", SDL_GetError();
            exit(1);
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (this-> renderer == NULL)
        {
            std::cout << "Failed to create renderer: ", SDL_GetError();
            exit(1);
        }

    }

    void start();

};

#endif
