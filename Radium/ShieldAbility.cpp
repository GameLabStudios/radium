#define _USE_MATH_DEFINES

#include "ShieldAbility.hpp"
#include <iostream>
#include <math.h>
#include "Shield.hpp"
#include "Entity.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"


ShieldAbility::ShieldAbility(Entity* entity) : Ability(entity)
{
    cooldown = 5.0f;
    timer = 0.0f;
    shieldLife = 2.0f;
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
        Vector2f shieldPosOffset = Vector2f((cos(rad) * 40.0f), (sin(rad) * -40.0f));
        Vector2f shieldPos = Vector2f((mBody->GetPosition().x * Game::m2p) + shieldPosOffset.x, (mBody->GetPosition().y * Game::m2p) + shieldPosOffset.y);
        std::cout << " new position: " << shieldPos.x << " " << shieldPos.y << std::endl;
        std::unique_ptr<Entity> newShield(new Shield(shieldPos, shieldLife));
        GameWorld::getInstance()->addEntityToWorld(std::move(newShield));
    }
}

void ShieldAbility::onUpdate(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}