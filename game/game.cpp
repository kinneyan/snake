#include "game.hpp"

void Game::start()
{
    this->gameLoop();
    this->close();
}

void Game::gameLoop()
{
    // randomize the initial apple position
    this->apple.randomizePosition(SCREEN_WIDTH, SCREEN_HEIGHT, this->snake.getHead(), this->snake.getTail());

    while (!this->exitNow)
    {
        // update score
        std::stringstream title;
        title << "Snake score: " << this->score;
        SDL_SetWindowTitle(this->window, title.str().c_str());

        // display the game
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);
        this->apple.draw(this->renderer);
        this->snake.draw(this->renderer);
        SDL_RenderPresent(this->renderer);

        // get user input and update game variables
        getInput();
        this->snake.move();
        checkRules();

        // wait
        SDL_Delay(GAME_TIME);
        this->snake.setIgnoreNextInput(false);
    }
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
            if (this->snake.getDead())
            {
                this->resetGame();
                break;
            }
            switch (this->event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    this->exitNow = true;
                    break;
                case SDLK_UP:
                case SDLK_w:
                    if (this->snake.getIgnoreNextInput())
                    {
                        this->snake.setIgnoreNextInput(false);
                        break;
                    }
                    if (this->snake.getMY() == 0 - MOMENTUM)
                        break;
                    this->snake.setMX(0);
                    this->snake.setMY(MOMENTUM);
                    this->snake.setIgnoreNextInput(true);
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                    if (this->snake.getIgnoreNextInput())
                    {
                        this->snake.setIgnoreNextInput(false);
                        break;
                    }
                    if (this->snake.getMX() == 0 - MOMENTUM)
                        break;
                    this->snake.setMX(MOMENTUM);
                    this->snake.setMY(0);
                    this->snake.setIgnoreNextInput(true);
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    if (this->snake.getIgnoreNextInput())
                    {
                        this->snake.setIgnoreNextInput(false);
                        break;
                    }
                    if (this->snake.getMY() == MOMENTUM)
                        break;
                    this->snake.setMX(0);
                    this->snake.setMY(0 - MOMENTUM);
                    this->snake.setIgnoreNextInput(true);
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    if (this->snake.getIgnoreNextInput())
                    {
                        this->snake.setIgnoreNextInput(false);
                        break;
                    }
                    if (this->snake.getMX() == MOMENTUM)
                        break;
                    this->snake.setMX(0 - MOMENTUM);
                    this->snake.setMY(0);
                    this->snake.setIgnoreNextInput(true);
                    break;
            }
        }
    }
}

void Game::checkRules()
{
    if (!this->snake.inBounds(SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        this->snake.setDead(true);
        this->snake.setMX(0);
        this->snake.setMY(0);
    }

    if (this->snake.canEat(this->apple))
    {
        this->snake.eat();

        this->score += 100 * difficultyMult;
        // update difficultyMult based on speed

        this->apple.randomizePosition(SCREEN_WIDTH, SCREEN_HEIGHT, this->snake.getHead(), this->snake.getTail());
    }

    this->snake.checkAteSelf();

}

void Game::resetGame()
{
    this->score = 0;
    this->difficultyMult = 1;
    this->snake = Snake();
    this->snake.positionSnake(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->apple.randomizePosition(SCREEN_WIDTH, SCREEN_HEIGHT, this->snake.getHead(), this->snake.getTail());
}
