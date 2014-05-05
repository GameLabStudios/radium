#pragma once
#include "BehaviorNode.hpp"
using namespace AI;
class Enemy;
class MoveAction : public BehaviorNode
{
public:
    MoveAction(Enemy*);
    ~MoveAction();
    virtual BNodeStatus run();
private:
    Enemy* enemy;
};