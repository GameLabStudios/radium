#define _USE_MATH_DEFINES
#include "DodgeBullets.hpp"
#include <cmath>

DodgeBullets::DodgeBullets(BehaviorTree* bTree, Enemy* enemy) : Action(bTree)
{
    this->mEnemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus DodgeBullets::run()
{
    // Get the angle from the player to the enemy
    mEnemyAngleFromPlayer = atan2(mPlayer->getPosition().y - mEnemy->getPosition().y,
        mPlayer->getPosition().x - mEnemy->getPosition().x);

    // Get the angle from the player to the mouse
    mMousePosition = GameWorld::getInstance()->getMousePosition();
    mMouseAngleFromPlayer = atan2(mPlayer->getPosition().y - mMousePosition.y,
        mPlayer->getPosition().x - mMousePosition.x);

    // Check to see if the difference between the two angles is within the dodge range (45 degrees)
    float angleDiff = abs(mMouseAngleFromPlayer - mEnemyAngleFromPlayer);
    if (angleDiff > M_PI / 4)
    {
        mNodeStatus = FAILURE;
    }
    else
    {
        mNodeStatus = SUCCESS;
    }

    mBTree->currentNode = this;
    return mNodeStatus;
}

void DodgeBullets::doAction()
{
    mEnemyAngleFromMouse = atan2(mMousePosition.y - mEnemy->getPosition().y,
        mMousePosition.x - mEnemy->getPosition().x);

    mTargetPos.x = cos(mEnemyAngleFromMouse + M_PI) * mEnemy->getVelocity().x * 3;
    mTargetPos.y = sin(mEnemyAngleFromMouse + M_PI) * mEnemy->getVelocity().y * 3;

    mEnemy->rigidbody->body->SetLinearVelocity(b2Vec2(mTargetPos.x, mTargetPos.y));
}
