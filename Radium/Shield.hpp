#pragma once
#include <SFML/Graphics.hpp>
#include "Ability.hpp"
using namespace sf;

class Shield : public Ability
{
public:
    Shield();
    void useAbility();
    void update();

private:

public:

private:
    float cooldown;

};