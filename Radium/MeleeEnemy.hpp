#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Enemy.hpp"

/*
* The Melee Enemy acts as a zombie. All it cares about
* is going towards the player and killing him.
*/
class MeleeEnemy : public Enemy
{
public:
    MeleeEnemy(Vector2f position);
    virtual void buildBehaviorTree();
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void onEndContact(b2Fixture* other, b2Contact* contact);
};

