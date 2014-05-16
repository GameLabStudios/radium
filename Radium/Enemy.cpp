#include "Enemy.hpp"
#include "Game.hpp"
#include "SquareRigidbody.hpp"
#include <iostream>

Enemy::Enemy(Vector2f position)
{
    rectShape = RectangleShape(Vector2f(40.0f, 40.0f));
    rectShape.setOrigin(20.0f, 20.0f);
    setColor(Color::Red);
    rectShape.setFillColor(getColor());
    //set position
    setPosition(position);

    SquareRigidbody* rigidbody = addComponent<SquareRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(rectShape);
}

void Enemy::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(rectShape, states);
}

void Enemy::onUpdate(Time dt)
{
    getBTree()->update(dt);
}

/******Public Functions******/

#pragma region
float Enemy::getHealth() const
{
    return health;
}

int Enemy::getNumSides() const
{
    return numSides;
}

Vector2f Enemy::getVelocity() const
{
    return velocity;
}

Color Enemy::getColor() const
{
    return color;
}

float Enemy::getAlpha() const
{
    return alpha;
}

BehaviorTree* Enemy::getBTree() const
{
    return bTree;
}
#pragma endregion Getters

/******Protected Functions******/

#pragma region
void Enemy::setHealth(float health)
{
    this->health = health;
}

void Enemy::setNumSides(int numSides)
{
    this->numSides = numSides;
}

void Enemy::setVelocity(Vector2f velocity)
{
    this->velocity = velocity;
}

void Enemy::setColor(Color color)
{
    this->color = color;
}

void Enemy::setAlpha(float alpha)
{
    this->alpha = alpha;
}

void Enemy::setBTree(BehaviorTree* bTree)
{
    this->bTree = bTree;
}
#pragma endregion Setters

/******Private Functions******/
