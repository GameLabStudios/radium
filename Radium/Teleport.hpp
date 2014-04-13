#pragma once
#include <SFML/Graphics.hpp>
#include "Ability.hpp"
using namespace sf;

class Teleport: public Ability
{
public:
    Teleport();
    Vector3f useAbility();
    Vector3f useAbility(float angle);
    void update(Time dt);
    

private:

public:

private:
    float timer;
    float cooldown;
};