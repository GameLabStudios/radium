#include "AttackPlayerAction.hpp"
#include <iostream>

AttackPlayerAction::AttackPlayerAction()
{
}


AttackPlayerAction::~AttackPlayerAction()
{
}

BNodeStatus AttackPlayerAction::run()
{
    std::cout << "attacking that slut" << std::endl;
    return SUCCESS;
}