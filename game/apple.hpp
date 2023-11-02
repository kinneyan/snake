#ifndef APPLE_H
#define APPLE_H

#include <time.h>
#include <vector>
#include "SDL2/SDL.h"
#include "utils.hpp"
#include "block.hpp"

class Apple: public Block
{

private:

public:
    Apple(): Block(0, 0){};
    Apple(int x, int y): Block(x, y){};

    void draw(SDL_Renderer* renderer);
    void randomizePosition(int sWidth, int sHeight, std::vector<Block>::iterator head, std::vector<Block>::iterator tail);

};

#endif
