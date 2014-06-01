#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Enemy.hpp"

class MeleeEnemy : public Enemy
{
public:
    MeleeEnemy(Vector2f position);
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void onEndContact(b2Fixture* other, b2Contact* contact);
};

