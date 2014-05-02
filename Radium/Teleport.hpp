#pragma once
#include <SFML/Graphics.hpp>

#include "Ability.hpp"
using namespace sf;

class Teleport: public Ability
{
public:
    Teleport();
    Vector2f useAbility();
    Vector2f useAbility(b2Body *mBody, float angle);
    void update(Time dt);
    

private:

public:

private:
    float timer;
    float cooldown;
};