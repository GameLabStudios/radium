#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Ability.hpp"
using namespace sf;

class ShieldAbility : public Ability
{
public:
    ShieldAbility();
    void useAbility();
    void useAbility(b2Body *mBody, float angle);
    void update(Time dt);

private:

public:

private:
    float timer;
    float cooldown;
    float shieldLife;
    bool abilityDown;
};