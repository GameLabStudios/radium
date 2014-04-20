#pragma once
#include <SFML/System.hpp>
#include "BehaviorNode.hpp"
using namespace AI;
class Enemy;
class NearPlayerCondition : public BehaviorNode
{
public:
    NearPlayerCondition(Enemy*);
    ~NearPlayerCondition();
    virtual BNodeStatus   run();

private:
    float                 distance(sf::Vector2f, sf::Vector2f);

private:
    Enemy*                enemy;
    sf::Vector2f          playerPos;
    sf::Vector2f          enemyPos;
    float                 range = 5.0f;
};

