#pragma once
#include "BehaviorNode.hpp"
#include "Player.hpp"
using namespace AI;
class PlayerShootingCondition : public BehaviorNode
{
public:
    PlayerShootingCondition();
    ~PlayerShootingCondition();
    virtual BNodeStatus run();

private:
    Player* player;
};

