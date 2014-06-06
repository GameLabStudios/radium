#include "IsNearPlayer.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include "Gun.hpp"

IsNearPlayer::IsNearPlayer(BehaviorTree* bTree, Enemy* enemy, float range)
{
    this->mBTree = bTree;
    this->mEnemy = enemy;
    this->mRange = range * Game::m2p;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus IsNearPlayer::run()
{
    if (b2Distance(b2Vec2(mPlayer->getPosition().x, mPlayer->getPosition().y),
        b2Vec2(mEnemy->getPosition().x, mEnemy->getPosition().y)) < mRange)
    {
        mNodeStatus = SUCCESS;
    }
    else
    {
        // Check to see if the enemy has a gun attached to it,
        // and if so, have it stop firing.
        Gun* gun = mEnemy->getComponent<Gun>();
        if (gun != nullptr)
        {
            gun->setFiring(false);
        }

        mNodeStatus = FAILURE;
    }

    mBTree->currentNode = this;
    return mNodeStatus;
}

