#pragma once
#include "BehaviorNode.hpp"
#include "BehaviorTree.hpp"
#include "GameWorld.hpp"

namespace AI
{
    class Action : public BehaviorNode
    {
    public:
        Action(BehaviorTree* bTree) { this->mBTree = bTree; }
        virtual BNodeStatus run() = 0;  // inherited from BehaviorNode
        virtual void doAction() = 0;    // performs the action associated with this action node

    protected:
        BehaviorTree* mBTree;            // bTree of the enemy
        BNodeStatus mNodeStatus;         // status of the node
        Player* mPlayer;                // reference to the player
    };

}

