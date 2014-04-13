#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ability
{
public:
    Ability();
    void useAbility();
    virtual void update(Time dt);

private:

public:

private:
    float timer;
    float cooldown;
    bool abilityDown;
};