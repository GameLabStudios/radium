#include "PlayerShootingCondition.hpp"
#include "GameWorld.hpp"

PlayerShootingCondition::PlayerShootingCondition()
{
}


PlayerShootingCondition::~PlayerShootingCondition()
{
}

BNodeStatus PlayerShootingCondition::run()
{
    player = GameWorld::getInstance()->getPlayer();
    if (player->isShooting)
    {
        return SUCCESS;
    }
    return FAILURE;
}