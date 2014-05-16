#pragma once
#include <SFML/Graphics.hpp>
#include "BehaviorNode.hpp"
namespace AI
{
    class BehaviorTree
    {
    public:
        BehaviorTree();
        ~BehaviorTree();
        void              update(sf::Time dt);
        void              setRootNode(BehaviorNode*);

    public:
        BehaviorNode*     rootNode;       // root node of the behavior tree (first to be processed per update)
        BehaviorNode*     currentNode;    // the node last processed on this update (tree will perform action associated with it)
        BNodeStatus       treeStatus;     // the current status of the root node (aka the tree)
        float             nextUpdate = 4; // traverse the tree every 4 seconds
        float             updateTimer;    // increases every frame
    };
}

