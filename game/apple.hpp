#ifndef APPLE_H
#define APPLE_H

#include <stdlib.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "block.hpp"

class Apple: public Block
{

private:
    static int roundToMultiple(int num, int multiple);

public:
    Apple(): Block(0, 0){};
    Apple(int x, int y): Block(x, y){};

    void draw(SDL_Renderer* renderer);
    void randomizePosition(int sWidth, int sHeight);
    
};

#endif
