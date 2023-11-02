#include "snake.hpp"
#include <iostream>

void Snake::draw(SDL_Renderer* renderer)
{
    for (std::vector<Block>::iterator i = this->body.begin(); i < this->body.end(); i++)
    {
        i->draw(renderer);
    }
}

void Snake::eat(int x, int y)
{
    this->body.emplace(this->body.begin(), x, y);
}

void Snake::move()
{
    std::vector<Block>::iterator i = this->body.begin();
    this->body.emplace(i, i->x() + this->momentum_x, i->y() + this->momentum_y);
    this->body.pop_back();
}

bool Snake::inBounds(int sWidth, int sHeight)
{
    std::vector<Block>::iterator i = this->body.begin();
    std::cout << '(' << i->x() << ',' << i->y() << ')' << std::endl;
    if (i->x() <= 0 || i->x() >= sWidth)
        return false;
    else if (i->y() <= 0 || i->y() >= sHeight)
        return false;
    return true;
}
