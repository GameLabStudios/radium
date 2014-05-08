#include "MoveAction.hpp"
#include "Enemy.hpp"
#include "GameWorld.hpp"

MoveAction::MoveAction(Enemy* enemy)
{
    this->enemy = enemy;
}

MoveAction::~MoveAction()
{
}

BNodeStatus MoveAction::run()
{
    Vector2f playerPos = GameWorld::getInstance()->getPlayer()->getPosition();
    Vector2f direction = playerPos - enemy->getPosition();
    // Normalize shit i think
    if (direction.x != 0.0f)
    {
        direction.x = direction.x / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }
    if (direction.y != 0.0f)
    {
        direction.y = direction.y / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }

    return SUCCESS;
}