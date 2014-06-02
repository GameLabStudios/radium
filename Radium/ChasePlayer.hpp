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
    ChasePlayer(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();  // inherited from BehaviorNode
    virtual void   doAction(); // inherited from Action

private:
    float           angle;      // angle towards the player
    Vector2f        targetPos;  // the target position the enemy will head towards based on the angle from the player
    Enemy*          enemy;      // the enemy performing this action
};

