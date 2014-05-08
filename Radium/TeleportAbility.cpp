#include "TeleportAbility.hpp"
#include <iostream>


TeleportAbility::TeleportAbility(Entity* entity) : Ability(entity)
{
    cooldown = 5.0f;
    timer = 0.0f;
}

void TeleportAbility::useAbility()
{
    //should not use this one
}

void TeleportAbility::useAbility(b2Body *mBody, float rad)
{
    if (timer <= 0)
    {
        timer = cooldown;
        b2Vec2 jump = b2Vec2((cos(rad) * 10.0f), (sin(rad) * -10.0f));
        mBody->SetTransform(mBody->GetPosition() + jump, 0.0f);
    }
}


void TeleportAbility::onUpdate(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}