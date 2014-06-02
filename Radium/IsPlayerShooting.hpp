#pragma once
#include "BehaviorNode.hpp"
#include "BehaviorTree.hpp"
#include "GameWorld.hpp"

class IsPlayerShooting : public BehaviorNode
{
public:
    IsPlayerShooting(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();

private:
    BehaviorTree* bTree;
    BNodeStatus nodeStatus;
    Player* mPlayer;
    Enemy* enemy;
};

