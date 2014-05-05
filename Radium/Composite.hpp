#pragma once
#include "BehaviorNode.hpp"

namespace AI
{
    class Composite : public BehaviorNode
    {
    public:
        void addChild(BehaviorNode* child)
        {
            children.push_back(child);
        }

    protected:
        typedef std::vector<BehaviorNode*> Behaviors;
        Behaviors children;
    };
}
