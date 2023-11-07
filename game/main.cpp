#include "game.hpp"

#ifdef main
#undef main
#endif

int main()
{
    Game game;
    game.start();
    return 0;
}
