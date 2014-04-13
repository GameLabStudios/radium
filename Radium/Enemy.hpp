#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "BehaviorTree.hpp"
#include "Composite.hpp"
#include "Sequence.hpp"
#include "Selector.hpp"
#include "TestAction.hpp"
#include "TestCondition.hpp"

using namespace sf;
using namespace AI;

class Enemy : public Entity
{
public:
    Enemy();

private:
    virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
    virtual void updateCurrent(Time dt);

protected:
    void BuildBehaviorTree();

private:
    RectangleShape rectangle;
    float enemySpeed;
    float health;
    BehaviorTree* bTree;
    Sequence* root;
    TestCondition* condition;
    TestAction* action;
};

