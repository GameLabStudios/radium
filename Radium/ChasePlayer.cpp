#include "ChasePlayer.hpp"
#include <iostream>
using namespace std;

ChasePlayer::ChasePlayer(BehaviorTree* bTree) : Action(bTree)
{
    mPlayer = GameWorld::getInstance()->getPlayer();
}


ChasePlayer::~ChasePlayer()
{
}

BNodeStatus Action::run()
{
    //if (mPlayer->isShooting)
    //{
    //    nodeStatus = RUNNING;
    //}
    //else
    //{
    //    nodeStatus = SUCCESS;
    //}
    bTree->currentNode = this;
    return nodeStatus;
}

void Action::doAction()
{
    //if (nodeStatus == SUCCESS)
    //{
    //    cout << "caught player" << endl;
    //}
    //else if (nodeStatus == RUNNING)
    //{
    //    cout << "still chasing player" << endl;
    //}
}