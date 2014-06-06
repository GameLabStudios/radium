#include "ChasePlayer.hpp"
#include "Rigidbody.hpp"
#include "Game.hpp"
using namespace AI;

ChasePlayer::ChasePlayer(BehaviorTree* bTree, Enemy* enemy, float range) : Action(bTree)
{
    this->mEnemy = enemy;
    this->mPlayer = GameWorld::getInstance()->getPlayer();
    this->mRange = range * Game::m2p;
}

BNodeStatus ChasePlayer::run()
{
    if (b2Distance(b2Vec2(mPlayer->getPosition().x, mPlayer->getPosition().y),
        b2Vec2(mEnemy->getPosition().x, mEnemy->getPosition().y)) < mRange)
    {
        mNodeStatus = SUCCESS;
    }
    else
    {
        mNodeStatus = RUNNING;
    }
    mBTree->currentNode = this;
    return mNodeStatus;
}

void ChasePlayer::doAction()
{
    // get the angle from the player to the enemy
    mAngle = atan2(mPlayer->getPosition().y - mEnemy->getPosition().y,
        mPlayer->getPosition().x - mEnemy->getPosition().x);
    
    // get the x and y coordinates correlating to that angle
    mTargetPos.x = cos(mAngle) * mEnemy->getVelocity().x;
    mTargetPos.y = sin(mAngle) * mEnemy->getVelocity().y;
    
    // move the enemy towards that bitch
    mEnemy->rigidbody->body->SetLinearVelocity(b2Vec2(mTargetPos.x, mTargetPos.y));
}