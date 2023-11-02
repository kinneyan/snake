#include "game.hpp"

void Game::gameLoop()
{
    while (!this->exitNow)
    {
        // display the game
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);
        this->snake.draw(this->renderer);
        SDL_RenderPresent(this->renderer);

        // get user input and update game variables
        this->snake.move();
        checkRules();
        getInput();

        // wait
        SDL_Delay(this->time);
    }

    close();
}

void Game::getInput()
{
    while (SDL_PollEvent(&this->event) != 0)
    {
        if (this->event.type == SDL_QUIT)
        {
            this->exitNow = true;
        }
        else if (this->event.type == SDL_KEYDOWN)
        {
            switch (this->event.key.keysym.sym)
            {
                case SDLK_UP:
                case SDLK_w:
                    if (this->snake.getMY() == 0 - MOMENTUM || snake.getDead())
                        break;
                    this->snake.setMX(0);
                    this->snake.setMY(MOMENTUM);
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                    if (this->snake.getMX() == 0 - MOMENTUM || snake.getDead())
                        break;
                    this->snake.setMX(MOMENTUM);
                    this->snake.setMY(0);
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    if (this->snake.getMY() == MOMENTUM || snake.getDead())
                        break;
                    this->snake.setMX(0);
                    this->snake.setMY(0 - MOMENTUM);
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    if (this->snake.getMX() == MOMENTUM || snake.getDead())
                        break;
                    this->snake.setMX(0 - MOMENTUM);
                    this->snake.setMY(0);
                    break;
            }
        }
    }
}

void Game::checkRules()
{
    if (!snake.inBounds(SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        snake.setDead(true);
        snake.setMX(0);
        snake.setMY(0);
    }
}
