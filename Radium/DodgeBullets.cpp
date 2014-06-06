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
    mNodeStatus = SUCCESS;
    mBTree->currentNode = this;
    return mNodeStatus;
}

void DodgeBullets::doAction()
{
    mMousePosition = GameWorld::getInstance()->getMousePosition();
    mAngleFromMouse = atan2(mMousePosition.y - mEnemy->getPosition().y,
        mMousePosition.x - mEnemy->getPosition().x);

    mTargetPos.x = cos(mAngleFromMouse + M_PI) * mEnemy->getVelocity().x * 3;
    mTargetPos.y = sin(mAngleFromMouse + M_PI) * mEnemy->getVelocity().y * 3;

    mEnemy->rigidbody->body->SetLinearVelocity(b2Vec2(mTargetPos.x, mTargetPos.y));
}
