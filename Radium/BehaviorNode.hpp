#pragma once
#include <vector>

namespace AI
{
    enum BNodeStatus { SUCCESS, RUNNING, FAILURE, NONE };

    class BehaviorNode
    {
    public:
        virtual BNodeStatus  run() = 0;

    private:
        BNodeStatus          mStatus;
    };
}
