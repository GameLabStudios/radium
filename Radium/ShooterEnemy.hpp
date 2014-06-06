#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Entity.hpp"
#include "Enemy.hpp"
#include "Gun.hpp"

/*
* The Shooter Enemy is a ranged enemy that
* has the ability to shoot a gun at the player,
* capable of causing more damage to the player
* from a distance than the Melee or Doding Enemies.
*/
class ShooterEnemy : public Enemy
{
public:
    ShooterEnemy(Vector2f position);
    virtual void buildBehaviorTree();
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void onEndContact(b2Fixture* other, b2Contact* contact);

private:
    Gun* mGun;
};

