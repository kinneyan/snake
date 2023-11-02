#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL2/SDL.h"
#include "block.hpp"

#define MOMENTUM (0 - 20)

class Snake
{

private:
    int momentum_x = 0;
    int momentum_y = 0;
    bool dead;
    std::vector<Block> body;

    int round();

public:

    Snake()
    {
        this->body.emplace_back(500, 500);
        this->dead = false;
    }

    Snake(int x, int y)
    {
        this->body.emplace_back(x, y);
        this->dead = false;
    }

    int getMX()
    {
        return this->momentum_x;
    }

    void setMX(int mx)
    {
        this->momentum_x = mx;
    }

    int getMY()
    {
        return this->momentum_y;
    }

    void setMY(int my)
    {
        this->momentum_y = my;
    }

    void setDead(bool dead)
    {
        this->dead = dead;
    }

    bool getDead()
    {
        return this->dead;
    }

    void draw(SDL_Renderer* renderer);
    void eat(int x, int y);
    void move();
    bool inBounds(int sWidth, int sHeight);

};

#endif
