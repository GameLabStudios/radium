#include "Enemy.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>

Enemy::Enemy()
{
}

void Enemy::drawCurrent(RenderTarget& target, RenderStates states) const
{
}

void Enemy::updateCurrent(Time dt)
{
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

Vector2f Enemy::getPosition() const
{
    return position;
}

Color Enemy::getColor() const
{
    return color;
}

float Enemy::getAlpha() const
{
    return alpha;
}

BehaviorTree* Enemy::getBTreeRoot() const
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

void Enemy::setPosition(Vector2f position)
{
    this->position = position;
}

void Enemy::setColor(Color color)
{
    this->color = color;
}

void Enemy::setAlpha(float alpha)
{
    this->alpha = alpha;
}

void Enemy::setBTreeRoot(BehaviorTree* bTree)
{
    this->bTree = bTree;
}
#pragma endregion Setters

/******Private Functions******/
