#pragma once
#include "Bullet.hpp"
class EnemyBullet : public Bullet
{
public:
    EnemyBullet(Gun* gun, float damage);
    void makeRigidBody() override;
    void onBeginContact(b2Fixture* other, b2Contact* contact);
};

