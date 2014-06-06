#pragma once
#include "Action.hpp"
#include <cmath>

using namespace AI;
/*
* ChasePlayer Action causes the enemy to start
* chasing towards the player.
*/
class ChasePlayer : public Action
{
public:
    ChasePlayer(BehaviorTree* bTree, Enemy* enemy, float range);
    virtual BNodeStatus run();      // inherited from BehaviorNode
    virtual void        doAction(); // inherited from Action

private:
    float           mAngle;      // angle towards the player
    float           mRange;      // range to the targetPos
    Vector2f        mTargetPos;  // the target position the enemy will head towards based on the angle from the player
    Enemy*          mEnemy;      // the enemy performing this action
};

