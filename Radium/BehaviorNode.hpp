#pragma once
#include <vector>

namespace AI
{
    enum BNodeStatus { SUCCESS, FAILURE, NONE };

    class BehaviorNode
    {
    public:
        virtual BNodeStatus  run() = 0;

    private:
        BNodeStatus          status;
    };
}
