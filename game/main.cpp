#include "main.hpp"

void App::run()
{
    Game game(this->window);
    game.start();
    this->cleanup();
}

int main()
{
    App app;
    app.run();
    return 0;
}
