#include "EnemyBullet.hpp"
#include "CircleRigidbody.hpp"
#include "CollisionFilters.hpp"
#include "Player.hpp"


EnemyBullet::EnemyBullet(float damage) : Bullet(damage)
{
}

void EnemyBullet::makeRigidBody()
{
    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->setBits(Collision::ENEMY_BULLETS, ~Collision::ENEMY_BULLETS ^ Collision::ENEMIES);
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);
    rigidbody->body->SetBullet(true);
}

void EnemyBullet::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        playerPtr->takeDamage(mDamage);
    }

    destroy();
}

