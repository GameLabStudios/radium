#include "TeleportAbility.hpp"
#include "Rigidbody.hpp"
#include <iostream>


TeleportAbility::TeleportAbility(Entity* entity) : Ability(entity)
{
    cooldown = 5.0f;
    timer = 0.0f;
}

void TeleportAbility::useAbility(float rad)
{
    if (timer <= 0)
    {
        timer = cooldown;
        b2Vec2 jump = b2Vec2((cos(rad) * 10.0f), (sin(rad) * 10.0f));
        mEntity->rigidbody->body->SetTransform(mEntity->rigidbody->body->GetPosition() + jump, 0.0f);
    }
}


void TeleportAbility::onUpdate(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}