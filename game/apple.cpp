#include "apple.hpp"

void Apple::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.x = this->x();
    rect.y = this->y();
    rect.w = this->w();
    rect.h = this->h();

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Apple::randomizePosition(int sWidth, int sHeight, std::vector<Block>::iterator block, std::vector<Block>::iterator tail)
{
    srand(time(NULL));

    int xPos;
    int yPos;

    bool safePos = false;
    while (!safePos)
    {
        safePos = true;
        xPos = roundToMultiple(((rand() % (sWidth - TILE_SIZE) - 0 + 1)) - 0, TILE_SIZE);
        yPos = roundToMultiple(((rand() % (sHeight - TILE_SIZE) - 0 + 1)) - 0, TILE_SIZE);

        for (;block < tail; block++)
        {
            if (block->x() == xPos && block->y() == yPos)
                safePos = false;
        }
    }

    this->setX(xPos);
    this->setY(yPos);
}
