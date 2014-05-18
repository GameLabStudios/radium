#include "MeleeEnemy.hpp"
#include "ChasePlayer.hpp"

MeleeEnemy::MeleeEnemy(Vector2f position) : Enemy(position)
{
    setHealth(100.0f);
    setVelocity(Vector2f(1.5f, 1.5f));
    bTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(bTree);
}

void Enemy::buildBehaviorTree()
{
    ChasePlayer* chase = new ChasePlayer(bTree);
    bTree->setRootNode(chase);
}
