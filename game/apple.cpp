#include "apple.hpp"
#include <iostream>

void Apple::draw(SDL_Renderer* renderer)
{
    //std::cout << x() << ',' << y() << std::endl;
    SDL_Rect rect;
    rect.x = x();
    rect.y = y();
    rect.w = w();
    rect.h = h();

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
