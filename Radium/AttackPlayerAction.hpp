#pragma once
#include "BehaviorNode.hpp"
using namespace AI;
class AttackPlayerAction : public BehaviorNode
{
public:
    AttackPlayerAction();
    ~AttackPlayerAction();
    virtual BNodeStatus run();
};

