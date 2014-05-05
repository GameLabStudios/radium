#pragma once
#include "BehaviorNode.hpp"
using namespace AI;

class TestCondition : public BehaviorNode
{
public :
    virtual BNodeStatus run();
private:
    int count = 0;
};