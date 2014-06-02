#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Entity.hpp"
#include "Enemy.hpp"

class DodgingEnemy : public Enemy
{
public:
    DodgingEnemy(Vector2f position);
    virtual void buildBehaviorTree();
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void onEndContact(b2Fixture* other, b2Contact* contact);
};

