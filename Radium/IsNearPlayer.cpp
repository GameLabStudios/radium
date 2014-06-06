#include "IsNearPlayer.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"

IsNearPlayer::IsNearPlayer(BehaviorTree* bTree, Enemy* enemy)
{
    this->bTree = bTree;
    this->enemy = enemy;
    mPlayer = GameWorld::getInstance()->getPlayer();
}

BNodeStatus IsNearPlayer::run()
{
    if (b2Distance(b2Vec2(mPlayer->getPosition().x, mPlayer->getPosition().y),
        b2Vec2(enemy->getPosition().x, enemy->getPosition().y)) < 12.0f * Game::m2p)
    {
        nodeStatus = SUCCESS;
    }
    else
    {
        nodeStatus = FAILURE;
    }
    bTree->currentNode = this;
    return nodeStatus;
}

