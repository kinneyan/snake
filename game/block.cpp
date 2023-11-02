#include "block.hpp"

void Block::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.x = this->pos_x;
    rect.y = this->pos_y;
    rect.w = this->width;
    rect.h = this->height;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
