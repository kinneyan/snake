#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL2/SDL.h"
#include "utils.hpp"
#include "block.hpp"
#include "apple.hpp"

#define MOMENTUM (0 - TILE_SIZE)

class Snake
{

private:
    int momentum_x = 0;
    int momentum_y = 0;
    int applesAte = 0;
    bool dead;
    std::vector<Block> body;
    // only allow one input per timing cycle
    bool ignoreNextInput = false;

    int round();

public:

    Snake()
    {
        this->dead = false;
    }

    Snake(int x, int y)
    {
        this->body.emplace_back(x, y);
        this->dead = false;
    }

    void positionSnake(const int sWidth, const int sHeight)
    {
        int x = (sWidth / 2) + (TILE_SIZE / 2);
        int y = (sHeight / 2) + (TILE_SIZE / 2);
        this->body.emplace(this->body.begin(), roundToMultiple(x, TILE_SIZE), roundToMultiple(y, TILE_SIZE));
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

    void setIgnoreNextInput(bool input)
    {
        this->ignoreNextInput = input;
    }

    bool getIgnoreNextInput()
    {
        return this->ignoreNextInput;
    }

    std::vector<Block>::iterator getHead()
    {
        return this->body.begin();
    }

    std::vector<Block>::iterator getTail()
    {
        return this->body.end();
    }

    void draw(SDL_Renderer* renderer);
    bool canEat(Block apple);
    void checkAteSelf();
    void eat();
    void move();
    bool inBounds(int sWidth, int sHeight);

};

#endif
