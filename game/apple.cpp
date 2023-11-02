#include "apple.hpp"

int Apple::roundToMultiple(int num, int multiple)
{
    if (multiple == 0)
        return num;
    int r = num % multiple;
    if (r == 0)
        return num;
    return num + multiple - r;
}

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

void Apple::randomizePosition(int sWidth, int sHeight, std::vector<Block>::iterator head, std::vector<Block>::iterator tail)
{
    srand(time(NULL));

    int xPos;
    int yPos;

    bool safePos = false;
    while (!safePos)
    {
        safePos = true;
        xPos = ((rand() % (sWidth - TILE_SIZE) - 0 + 1)) - 0;
        yPos = ((rand() % (sHeight - TILE_SIZE) - 0 + 1)) - 0;

        for (;head < tail; head++)
        {
            if (head->x() == xPos && head->y() == yPos)
                safePos = false;
        }
    }

    this->setX(roundToMultiple(xPos, TILE_SIZE));
    this->setY(roundToMultiple(yPos, TILE_SIZE));
}
