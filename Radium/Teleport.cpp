#include "Teleport.hpp"
#include <iostream>

Teleport::Teleport()
{
    cooldown = 5.0f;
    timer = 0.0f;
}

Vector2f Teleport::useAbility()
{
    if (timer <= 0)
    {
        std::cout << "teleport" << std::endl;
        timer = cooldown;
    }
    return Vector2f(0, 0);
}

Vector2f Teleport::useAbility(b2Body *mBody, float angle)
{
    if (timer <= 0)
    {
        std::cout << "teleport2" << std::endl;
        timer = cooldown;

        mBody->SetTransform(mBody->GetPosition() + b2Vec2(10, 0), 0.f);
        return Vector2f(10, 0);
    }
    return Vector2f(0, 0);
}


void Teleport::update(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}