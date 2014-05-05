#include "BehaviorTree.hpp"
#include <iostream>

namespace AI
{
    BehaviorTree::BehaviorTree()
    {
    }


    BehaviorTree::~BehaviorTree()
    {
    }

    void BehaviorTree::update()
    {
        treeStatus = rootNode->run();
    }

    void BehaviorTree::setRootNode(BehaviorNode* root)
    {
        rootNode = root;
    }
}
