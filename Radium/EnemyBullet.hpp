#pragma once
#include "Bullet.hpp"
class EnemyBullet : public Bullet
{
public:
    EnemyBullet(float damage);
    void makeRigidBody() override;
    void EnemyBullet::onBeginContact(b2Fixture* other, b2Contact* contact);
};

