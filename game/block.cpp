#include "block.hpp"

void Block::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.x = this->pos_x;
    rect.y = this->pos_y;
    rect.w = this->w;
    rect.h = this->h;

    SDL_SetRenderDrawColor(renderer, 108, 187, 60, 255);
    SDL_RenderFillRect(renderer, &rect);
}
