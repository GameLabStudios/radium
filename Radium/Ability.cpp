#include "Ability.hpp"
#include <iostream>

Ability::Ability()
{

}

void Ability::useAbility()
{
    std::cout << "virtual" << std::endl;
}

void Ability::update(Time dt)
{

}



