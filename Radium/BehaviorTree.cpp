#include "BehaviorTree.hpp"
#include "Action.hpp"
using namespace sf;
namespace AI
{
    BehaviorTree::BehaviorTree()
    {
        currentNode = NULL;
        updateTimer = nextUpdate / 2.0f;
    }


    BehaviorTree::~BehaviorTree()
    {
    }

    void BehaviorTree::update(Time dt)
    {
        updateTimer += dt.asSeconds();
        if (updateTimer >= nextUpdate)
        {
            treeStatus = rootNode->run();
            updateTimer = 0;
        }

        // Perform the current action per tick
        if (treeStatus == RUNNING || treeStatus == SUCCESS)
        {
            Action* actionPtr = dynamic_cast<Action*>(currentNode);
            if (actionPtr != nullptr)
            {
                actionPtr->doAction();
            }
        }
    }

    void BehaviorTree::setRootNode(BehaviorNode* root)
    {
        rootNode = root;
    }

    void BehaviorTree::setUpdateFrequency(float timer)
    {
        nextUpdate = timer;
    }
}
