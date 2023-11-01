#include "game.hpp"

void Game::gameLoop()
{
    int temp = 0;
    while (!this->exitNow)
    {
        // display the game
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);
        this->snake.draw(this->renderer);
        SDL_RenderPresent(this->renderer);

        // get user input and update game variables
        this->snake.move();
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
                // add checks inc ase user tries to move backwards
                case SDLK_w:
                    this->snake.setMX(0);
                    this->snake.setMY(MOMENTUM);
                    break;
                case SDLK_a:
                    this->snake.setMX(MOMENTUM);
                    this->snake.setMY(0);
                    break;
                case SDLK_s:
                    this->snake.setMX(0);
                    this->snake.setMY(0 - MOMENTUM);
                    break;
                case SDLK_d:
                    this->snake.setMX(0 - MOMENTUM);
                    this->snake.setMY(0);
                    break;
                case SDLK_UP:
                    this->snake.setMX(0);
                    this->snake.setMY(MOMENTUM);
                    break;
                case SDLK_LEFT:
                    break;
                case SDLK_DOWN:
                    break;
                case SDLK_RIGHT:
                    break;
            }
        }
    }
}
