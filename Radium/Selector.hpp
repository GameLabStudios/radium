#pragma once
#include "Composite.hpp"

namespace AI
{
    class Selector : public Composite
    {
        virtual BNodeStatus run() override
        {
            BNodeStatus status;
            for (BehaviorNode* child : mChildren)
            {
                status = child->run();

                // If a child does not fail, return with same status from this selector.
                if (status != FAILURE)
                {
                    return status;
                }
            }
            // At end of children and last status is failure.
            // This means we failed to select a child.
            if (status == FAILURE)
            {
                return status;
            }
            // Unexpected break from loop.
            return NONE;
        }
    };
}