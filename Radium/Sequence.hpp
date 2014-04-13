#pragma once
#include "Composite.hpp"

namespace AI
{
    class Sequence : public Composite
    {
        BNodeStatus run() override
        {
            BNodeStatus status;
            for (BehaviorNode* child : children)
            {
                status = child->run();
                
                // If status is not success, return that status for this sequence.
                if (status != SUCCESS)
                {
                    return status;
                }
            }
            // At end of children and last status is success.
            // This means we succeeded running through our sequence.
            if (status == SUCCESS)
            {
                return status;
            }
            // Unexpected break out of loop.
            return NONE;
        }
    };
}