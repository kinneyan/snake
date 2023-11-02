#include "snake.hpp"

void Snake::draw(SDL_Renderer* renderer)
{
    for (std::vector<Block>::iterator i = this->body.begin(); i < this->body.end(); i++)
    {
        i->draw(renderer);
    }
}

bool Snake::canEat(Block apple)
{
    std::vector<Block>::iterator i = this->body.begin();
    return i->x() == apple.x() && i->y() == apple.y();
}

void Snake::checkAteSelf()
{
    std::vector<Block>::iterator head = this->body.begin();
    for (std::vector<Block>::iterator i = this->body.begin() + 1; i < this->body.end(); i++)
    {
        if (head->x() == i->x() && head->y() == i->y())
        {
            this->dead = true;
            break;
        }
    }
}

void Snake::eat()
{
    std::vector<Block>::iterator i = this->body.begin();
    this->body.emplace(i, i->x() + this->momentum_x, i->y() + this->momentum_y);
    ++this->applesAte;
}

void Snake::move()
{
    if (this->dead)
        return;
    std::vector<Block>::iterator i = this->body.begin();
    this->body.emplace(i, i->x() + this->momentum_x, i->y() + this->momentum_y);
    this->body.pop_back();
}

bool Snake::inBounds(int sWidth, int sHeight)
{
    std::vector<Block>::iterator i = this->body.begin();
    if (i->x() < 0 || i->x() + TILE_SIZE > sWidth)
        return false;
    else if (i->y() < 0 || i->y() + TILE_SIZE > sHeight)
        return false;
    return true;
}
