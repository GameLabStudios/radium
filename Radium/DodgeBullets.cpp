#define _USE_MATH_DEFINES
#include "DodgeBullets.hpp"
#include <cmath>

DodgeBullets::DodgeBullets(BehaviorTree* bTree, Enemy* enemy) : Action(bTree)
{
    this->enemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus DodgeBullets::run()
{
    nodeStatus = SUCCESS;
    bTree->currentNode = this;
    return nodeStatus;
}

void DodgeBullets::doAction()
{
    mousePosition = GameWorld::getInstance()->getMousePosition();
    angleFromMouse = atan2(mousePosition.y - enemy->getPosition().y,
        mousePosition.x - enemy->getPosition().x);

    targetPos.x = cos(angleFromMouse + M_PI) * enemy->getVelocity().x * 3;
    targetPos.y = sin(angleFromMouse + M_PI) * enemy->getVelocity().y * 3;

    enemy->rigidbody->body->SetLinearVelocity(b2Vec2(targetPos.x, targetPos.y));
}
