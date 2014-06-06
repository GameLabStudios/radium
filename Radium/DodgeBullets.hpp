#pragma once
#include "Action.hpp"

class DodgeBullets : public Action
{
public:
    DodgeBullets(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();
    virtual void doAction();

private:
    Enemy*      mEnemy;
    float       mEnemyAngleFromMouse;
    float       mEnemyAngleFromPlayer;
    float       mMouseAngleFromPlayer;
    Vector2f    mMousePosition;
    Vector2f    mTargetPos;
};

