#include "ChasePlayer.hpp"
#include "Rigidbody.hpp"
#include <iostream>
using namespace AI;

ChasePlayer::ChasePlayer(BehaviorTree* bTree, Enemy* enemy) : Action(bTree)
{
    this->enemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}


ChasePlayer::~ChasePlayer()
{
}

BNodeStatus Action::run()
{
    nodeStatus = SUCCESS;
    bTree->currentNode = this;
    return nodeStatus;
}

void ChasePlayer::doAction()
{
    angle = atan2(mPlayer->getPosition().y - enemy->getPosition().y,
        mPlayer->getPosition().x - enemy->getPosition().x);
    
    targetPos.x = cos(angle) * enemy->getVelocity().x;
    targetPos.y = sin(angle) * enemy->getVelocity().y;
    
    enemy->rigidbody->body->ApplyLinearImpulse(b2Vec2(targetPos.x, targetPos.y), enemy->rigidbody->body->GetWorldCenter(), true);
}