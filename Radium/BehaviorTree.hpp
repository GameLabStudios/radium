#pragma once
#include "BehaviorNode.hpp"

namespace AI
{
    class BehaviorTree : public BehaviorNode
    {
    public:
        BehaviorTree();
        ~BehaviorTree();
        void update();
        void setRootNode(BehaviorNode*);
        BNodeStatus run();

    public:
        BehaviorNode* rootNode;
        BNodeStatus treeStatus;
    };
}

