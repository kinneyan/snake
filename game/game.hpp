#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include "SDL2/SDL.h"
#include "utils.hpp"
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
        SDL_DestroyRenderer(this->renderer);
    }

    void getInput();
    void checkRules();
    void gameLoop();

public:
    Game(SDL_Window* win)
    {
        this->window = win;
        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (this-> renderer == NULL)
        {
            std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
            exit(1);
        }

        this->snake.positionSnake(SCREEN_WIDTH, SCREEN_HEIGHT);

    }

    void start();

};

#endif
