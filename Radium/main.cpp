#include "Game.hpp"
#include <stdexcept>
#include <time.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include <Box2D/Box2D.h>

int main()
{
#if _DEBUG
    try
    {
#endif
        srand((unsigned)time(NULL));
        Game& game = Game::getInstance();
        game.run();
#if _DEBUG
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
#endif
    return EXIT_SUCCESS;
}