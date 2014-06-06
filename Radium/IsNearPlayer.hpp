#pragma once
#include "BehaviorNode.hpp"
#include "BehaviorTree.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

class IsNearPlayer : public BehaviorNode
{
public:
    IsNearPlayer(BehaviorTree* bTree, Enemy* enemy);
    virtual BNodeStatus run();

private:
    BehaviorTree* mBTree;
    BNodeStatus mNodeStatus;
    Player* mPlayer;
    Enemy* mEnemy;
};

