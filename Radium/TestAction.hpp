#pragma once
#include "BehaviorNode.hpp"
using namespace AI;

class TestAction : public BehaviorNode
{
public:
    virtual BNodeStatus run();
private:
};