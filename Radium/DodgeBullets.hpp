#pragma once
#include "Action.hpp"

class DodgeBullets : public Action
{
public:
    DodgeBullets(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();
    virtual void doAction();

private:
    Enemy* enemy;
    float angleFromMouse;
    Vector2f mousePosition;
    Vector2f targetPos;
};

