#pragma once
#include "Action.hpp"
using namespace AI;

class ShootPlayer : public Action
{
public:
    ShootPlayer(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();      // inherited from BehaviorNode
    virtual void        doAction(); // inherited from Action

private:
    Player* mPlayer;
    Enemy*  mEnemy;
    float   mAngle;
};

