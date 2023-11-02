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

void Apple::randomizePosition(int sWidth, int sHeight)
{
    srand(time(NULL));
    int x = ((rand() % sWidth - 0 + 1)) - 0;
    int y = ((rand() % sHeight - 0 + 1)) - 0;
    this->setX(roundToMultiple(x, TILE_SIZE));
    this->setY(roundToMultiple(y, TILE_SIZE));
}
