#include "TestAction.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>

BNodeStatus TestAction::run()
{

    int randomNumber = rand() % 100 + 1;
    std::cout << "randomNumber: " << randomNumber << std::endl;

    if (randomNumber <= 33)
    {
        return SUCCESS;
    }
    else if (randomNumber > 33 && randomNumber <= 66)
    {
        return FAILURE;
    }
    else
    {
        return NONE;
    }
}