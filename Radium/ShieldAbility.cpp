#define _USE_MATH_DEFINES

#include "ShieldAbility.hpp"
#include <iostream>
#include <math.h>
#include "Shield.hpp"
#include "GameWorld.hpp"


ShieldAbility::ShieldAbility()
{
    cooldown = 5.0f;
    timer = 0.0f;
    shieldLife = 5.0f;
}

void ShieldAbility::useAbility()
{
    //should not use this one
}

void ShieldAbility::useAbility(b2Body *mBody, float rad)
{
    if (timer <= 0)
    {
        timer = cooldown;
        Vector2f shieldPos = Vector2f(mBody->GetPosition().x, mBody->GetPosition().y);
        Shield newShield = Shield(shieldPos, shieldLife);
        GameWorld::getInstance()->addEntityToWorld(&newShield);
    }
}

void ShieldAbility::update(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}