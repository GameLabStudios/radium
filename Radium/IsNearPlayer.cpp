#include "IsNearPlayer.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"

IsNearPlayer::IsNearPlayer(BehaviorTree* bTree, Enemy* enemy)
{
    this->mBTree = bTree;
    this->mEnemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus IsNearPlayer::run()
{
    if (b2Distance(b2Vec2(mPlayer->getPosition().x, mPlayer->getPosition().y),
        b2Vec2(mEnemy->getPosition().x, mEnemy->getPosition().y)) < 12.0f * Game::m2p)
    {
        mNodeStatus = SUCCESS;
    }
    else
    {
        mNodeStatus = FAILURE;
    }
    mBTree->currentNode = this;
    return mNodeStatus;
}

