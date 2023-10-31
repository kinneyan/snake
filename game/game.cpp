#include "game.hpp"

void Game::getInput()
{
    while (SDL_PollEvent(&this->event) != 0)
    {
        if (this->event.type == SDL_QUIT)
        {
            this->exitNow = true;
        }
    }
}

void Game::gameLoop()
{
    while (!this->exitNow)
    {
        SDL_SetRenderDrawColor(this->renderer, 0,96,0,255);
        SDL_RenderClear(this->renderer);

        getInput();

        SDL_RenderPresent(this->renderer);

        SDL_Delay(16);
    }

    Game::close();
}
