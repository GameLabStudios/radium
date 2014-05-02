#define _USE_MATH_DEFINES

#include "Teleport.hpp"
#include <iostream>
#include <math.h>


Teleport::Teleport()
{
    cooldown = 5.0f;
    timer = 0.0f;
}

void Teleport::useAbility()
{
    //should not use this one
}

void Teleport::useAbility(b2Body *mBody, float rad)
{
    if (timer <= 0)
    {
        timer = cooldown;
        b2Vec2 jump = b2Vec2((cos(rad) * 10.0f), (sin(rad) * -10.0f));
        mBody->SetTransform(mBody->GetPosition() + jump, 0.0f);
    }
}


void Teleport::update(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}