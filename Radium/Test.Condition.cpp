#include "TestCondition.hpp"
#include <cstring>
#include <iostream>

BNodeStatus TestCondition::run()
{
    std::cout << "count: " << count << std::endl;
    if (count % 3 == 0)
    {
        count++;
        return SUCCESS;
    }
    else
    {
        count++;
        return FAILURE;
    }
}