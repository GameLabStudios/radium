#pragma once
#include <SFML/Graphics.hpp>

#include "Ability.hpp"
using namespace sf;

class TeleportAbility: public Ability
{
public:
    TeleportAbility(Entity* entity);
    virtual void useAbility(float angle);
    virtual void onUpdate(Time dt);

private:
    float timer;
    float cooldown;
};