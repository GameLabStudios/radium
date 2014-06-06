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
    BehaviorTree* mBTree;
    BNodeStatus mNodeStatus;
    Player* mPlayer;
    Enemy* mEnemy;
};

