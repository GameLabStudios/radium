#pragma once
#include <SFML/System.hpp>
#include "BehaviorNode.hpp"
using namespace AI;
using namespace sf;
class Enemy;
class DodgeShotsAction : public BehaviorNode
{
public:
    DodgeShotsAction(Enemy*);
    ~DodgeShotsAction();
    virtual BNodeStatus run();

private:
    Enemy* enemy;
    sf::Vector2f playerPos;
    sf::Vector2f direction;
};

