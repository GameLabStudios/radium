#include "Enemy.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>

Enemy::Enemy()
{
    rectangle.setSize(Vector2f(50, 50));
    rectangle.setFillColor(Color::Red);
    rectangle.setOutlineColor(Color::Green);
    rectangle.setOutlineThickness(5.0f);
    BuildBehaviorTree();
}

void Enemy::drawCurrent(RenderTarget& target, RenderStates states) const
{
    target.draw(rectangle, states);
}

void Enemy::updateCurrent(Time dt)
{
    std::cout << "in update" << std::endl;
    bTree->update();
}

void Enemy::BuildBehaviorTree()
{
    bTree = new BehaviorTree();
    root = new Sequence();
    condition = new TestCondition();
    action = new TestAction();
    root->addChild(condition);
    root->addChild(action);

    bTree->setRootNode(root);
}