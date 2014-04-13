#include "BehaviorTree.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

namespace AI
{
    BehaviorTree::BehaviorTree()
    {
        srand(time(NULL));
    }


    BehaviorTree::~BehaviorTree()
    {
    }

    BNodeStatus BehaviorTree::run()
    {
        return FAILURE;
    }

    void BehaviorTree::update()
    {
        treeStatus = rootNode->run();
        if (treeStatus == SUCCESS)
        {
            std::cout << "bTree success!" << std::endl;
        }
        else if (treeStatus == FAILURE)
        {
            std::cout << "bTree failure!" << std::endl;
        }
        else
        {
            std::cout << "bTree none!" << std::endl;
        }
    }

    void BehaviorTree::setRootNode(BehaviorNode* root)
    {
        treeStatus = SUCCESS;
        rootNode = root;
    }
}
