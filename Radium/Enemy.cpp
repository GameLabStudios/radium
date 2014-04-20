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
    setSpeed(enemySpeed);
}

void Enemy::drawCurrent(RenderTarget& target, RenderStates states) const
{
    target.draw(rectangle, states);
}

void Enemy::updateCurrent(Time dt)
{
    bTree->update();
}

void Enemy::BuildBehaviorTree()
{
    bTree = new BehaviorTree();
    rootSequence = new Sequence();
    moving = new MoveAction(this);
    selection = new Selector();
    dodgeSequence = new Sequence();
    shooting = new PlayerShootingCondition();
    dodge = new DodgeShotsAction(this);
    attackSequence = new Sequence();
    nearby = new NearPlayerCondition(this);
    attacking = new AttackPlayerAction();

    rootSequence->addChild(moving);
    rootSequence->addChild(selection);

    selection->addChild(dodgeSequence);
    
    dodgeSequence->addChild(shooting);
    dodgeSequence->addChild(nearby);
    dodgeSequence->addChild(dodge);
    
    selection->addChild(attackSequence);
    attackSequence->addChild(nearby);
    attackSequence->addChild(attacking);

    bTree->setRootNode(rootSequence);
}

inline void Enemy::setSpeed(float speed)
{
    enemySpeed = speed;
}

inline float Enemy::getSpeed() const
{
    return enemySpeed;
}