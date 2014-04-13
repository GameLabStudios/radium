#include "Game.hpp"
#include <stdexcept>
#if _DEBUG
#include <iostream>
#endif

int main()
{
#if _DEBUG
    try
    {
#endif
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