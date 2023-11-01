#include "snake.hpp"

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
