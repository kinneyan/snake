#ifndef BLOCK_H
#define BLOCK_H

#include "SDL2/SDL.h"

#define TILE_SIZE 20

class Block
{

private:
    int pos_x;
    int pos_y;
    int width = TILE_SIZE;
    int height = TILE_SIZE;

public:
    Block(){};
    Block(int aX, int aY)
    {
        this->pos_x = aX;
        this->pos_y = aY;
    }

    int x()
    {
        return this->pos_x;
    }

    void setX(int x)
    {
        this->pos_x = x;
    }

    int y()
    {
        return this->pos_y;
    }

    void setY(int y)
    {
        this->pos_y = y;
    }

    int w()
    {
        return this->width;
    }

    int h()
    {
        return this->height;
    }

    void draw(SDL_Renderer* renderer);

};

#endif
