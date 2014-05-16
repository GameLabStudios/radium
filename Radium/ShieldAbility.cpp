#define _USE_MATH_DEFINES

#include "ShieldAbility.hpp"
#include <iostream>
#include <math.h>
#include "Shield.hpp"
#include "Entity.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include "Rigidbody.hpp"


ShieldAbility::ShieldAbility(Entity* entity) : Ability(entity)
{
    cooldown = 5.0f;
    timer = 0.0f;
    shieldLife = 2.0f;
}

void ShieldAbility::useAbility(float rad)
{
    if (timer <= 0)
    {
        std::cout << "created shield at " << (mEntity->rigidbody->body->GetPosition().x)  << std::endl;
        timer = cooldown;
        Vector2f shieldPos = Vector2f(40.0f, 0.0f) * Game::p2m;

        std::unique_ptr<Entity> newShield(new Shield(shieldPos, shieldLife));
        std::cout << "shield at " << newShield->getPosition().x << std::endl;
        GameWorld::getInstance()->addEntityToWorld(std::move(newShield));
        //mEntity->attachChild(std::move(newShield));
    }
}

void ShieldAbility::onUpdate(Time dt)
{
    if (timer > 0)
    {
        timer -= dt.asSeconds();
    }
}