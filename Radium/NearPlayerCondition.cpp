#include "NearPlayerCondition.hpp"
#include "Enemy.hpp"
#include "GameWorld.hpp"
#include <cmath>
using namespace sf;

NearPlayerCondition::NearPlayerCondition(Enemy* enemy)
{
    this->enemy = enemy;
}


NearPlayerCondition::~NearPlayerCondition()
{
}

BNodeStatus NearPlayerCondition::run()
{
    playerPos = GameWorld::getInstance()->getPlayer()->getPosition();
    enemyPos = enemy->getPosition();
    if (distance(playerPos, enemyPos) < range)
    {
        return SUCCESS;
    }
    return FAILURE;
}

float NearPlayerCondition::distance(Vector2f playerPos, Vector2f enemyPos)
{
    return sqrt((pow(playerPos.x - enemyPos.x , 2) + pow(playerPos.y - enemyPos.y, 2)));
}