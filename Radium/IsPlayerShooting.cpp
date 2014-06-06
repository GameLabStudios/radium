#include "IsPlayerShooting.hpp"


IsPlayerShooting::IsPlayerShooting(BehaviorTree* bTree, Enemy* enemy)
{
    this->mEnemy = enemy;
    this->mBTree = bTree;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus IsPlayerShooting::run()
{
    if (mPlayer->getIsShooting())
    {
        mBTree->currentNode = this;
        mNodeStatus = SUCCESS;
    }
    else
    {
        mNodeStatus = FAILURE;
    }
    mBTree->currentNode = this;
    return mNodeStatus;
}
