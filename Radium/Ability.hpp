#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Component.hpp"
using namespace sf;

class Ability : public Component
{
public:
    Ability(Entity* entity);
    void useAbility();

private:
    float timer;
    float cooldown;
    bool abilityDown;
};