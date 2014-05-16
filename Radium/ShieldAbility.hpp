#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Ability.hpp"

using namespace sf;

class ShieldAbility : public Ability
{
public:
                 ShieldAbility(Entity* entity);
    virtual void useAbility(float angle);
    virtual void onUpdate(Time dt);

private:

public:

private:
    float timer;
    float cooldown;
    float shieldLife;
    bool abilityDown;
};