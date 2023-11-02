#ifndef APPLE_H
#define APPLE_H

#include "SDL2/SDL.h"
#include "block.hpp"
#include <iostream>

class Apple: public Block
{

public:
    Apple(): Block(300, 300){};

    Apple(int x, int y): Block(x, y){};

    void draw(SDL_Renderer* renderer);
};

#endif
