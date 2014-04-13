#include "Teleport.hpp"
#include <iostream>

Teleport::Teleport()
{
    cooldown = 5.0f;
    timer = 0.0f;
}

Vector3f Teleport::useAbility()
{
    if (timer <= 0)
    {
        std::cout << "teleport" << std::endl;
        timer = cooldown;
    }
    return Vector3f(0, 0, 0);
}

Vector3f Teleport::useAbility(float angle)
{
    std::cout << "teleport2" << std::endl;
    return Vector3f(0, 0, 0);
}


void Teleport::update(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}