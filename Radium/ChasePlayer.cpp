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
    // get the angle from the player to the enemy
    angle = atan2(mPlayer->getPosition().y - enemy->getPosition().y,
        mPlayer->getPosition().x - enemy->getPosition().x);
    
    // get the x and y coordinates correlating to that angle
    targetPos.x = cos(angle) * enemy->getVelocity().x;
    targetPos.y = sin(angle) * enemy->getVelocity().y;
    
    // move the enemy towards that bitch
    enemy->rigidbody->body->SetLinearVelocity(b2Vec2(targetPos.x, targetPos.y));
}