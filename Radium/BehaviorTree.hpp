#pragma once
#include "BehaviorNode.hpp"

namespace AI
{
    class BehaviorTree
    {
    public:
        BehaviorTree();
        ~BehaviorTree();
        void              update();
        void              setRootNode(BehaviorNode*);

    public:
        BehaviorNode*     rootNode;
        BNodeStatus       treeStatus;
    };
}

