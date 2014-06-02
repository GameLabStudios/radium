#include "MeleeEnemy.hpp"
#include "ChasePlayer.hpp"
#include "Player.hpp"
#include "Box2D\Box2D.h"

MeleeEnemy::MeleeEnemy(Vector2f position) : Enemy(position)
{
    setHealth(100.0f);
    setVelocity(Vector2f(12.0f, 12.0f));
    bTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(bTree);
}

void Enemy::buildBehaviorTree()
{
    ChasePlayer* chase = new ChasePlayer(bTree, this);
    bTree->setRootNode(chase);
}

void MeleeEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
    }
}

void MeleeEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}