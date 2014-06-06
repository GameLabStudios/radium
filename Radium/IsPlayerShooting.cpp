#include "IsPlayerShooting.hpp"


IsPlayerShooting::IsPlayerShooting(BehaviorTree* bTree, Enemy* enemy)
{
    this->enemy = enemy;
    this->bTree = bTree;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus IsPlayerShooting::run()
{
    if (mPlayer->getIsShooting())
    {
        bTree->currentNode = this;
        return SUCCESS;
    }
    bTree->currentNode = this;
    return FAILURE;
}
