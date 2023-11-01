#ifndef BLOCK_H
#define BLOCK_H

#include "SDL2/SDL.h"

#define TILE_SIZE 20

class Block
{

private:
    int pos_x;
    int pos_y;
    int w = TILE_SIZE;
    int h = TILE_SIZE;

public:
    Block(int aX, int aY)
    {
        this->pos_x = aX;
        this->pos_y = aY;
    }

    int x()
    {
        return this->pos_x;
    }

    int y()
    {
        return this->pos_y;
    }

    void draw(SDL_Renderer* renderer);

};

#endif
