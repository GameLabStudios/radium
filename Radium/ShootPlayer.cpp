#include "ShootPlayer.hpp"
#include "Gun.hpp"


ShootPlayer::ShootPlayer(BehaviorTree* bTree, Enemy* enemy) : Action(bTree)
{
    this->mEnemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus ShootPlayer::run()
{
    mNodeStatus = SUCCESS;
    mEnemy->rigidbody->body->SetLinearVelocity(b2Vec2_zero);
    mBTree->currentNode = this;
    return mNodeStatus;
}

void ShootPlayer::doAction()
{
    mEnemy->getComponent<Gun>()->setFiring(true);
}