#pragma once
#include "BehaviorNode.hpp"
#include "BehaviorTree.hpp"
#include "GameWorld.hpp"

namespace AI
{
    class Action : public BehaviorNode
    {
    public:
        Action(BehaviorTree* bTree) { this->bTree = bTree; }
        virtual BNodeStatus run();  // inherited from BehaviorNode
        virtual void doAction();    // performs the action associated with this action node

    protected:
        BehaviorTree* bTree;        // bTree of the enemy
        BNodeStatus nodeStatus;     // status of the node
        Player* mPlayer;
    };

}
