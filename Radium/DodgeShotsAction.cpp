#include <math.h>
#include "DodgeShotsAction.hpp"
#include "GameWorld.hpp"
#include "Enemy.hpp"

DodgeShotsAction::DodgeShotsAction(Enemy* enemy)
{
    this->enemy = enemy;
}


DodgeShotsAction::~DodgeShotsAction()
{
}

BNodeStatus DodgeShotsAction::run()
{
    playerPos = GameWorld::getInstance()->getPlayer()->getPosition();
    direction = enemy->getPosition() - playerPos;

    // Normalize shit i think
    if (direction.x != 0.0f)
    {
        direction.x = direction.x / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }
    if (direction.y != 0.0f)
    {
        direction.y = direction.y / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }

    //enemy->move(direction * enemy->getSpeed());

    return SUCCESS;
}
