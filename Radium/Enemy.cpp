#include "Enemy.hpp"
#include "Game.hpp"
#include "SquareRigidbody.hpp"

Enemy::Enemy(Vector2f position)
{
    rectShape = RectangleShape(Vector2f(40.0f, 40.0f));
    //set position
    setPosition(position);

    SquareRigidbody* rigidbody = addComponent<SquareRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(rectShape);
}

/******Public Functions******/

void Enemy::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(rectShape, states);
}

void Enemy::onUpdate(Time dt)
{
    getBTree()->update(dt);
}

void Enemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{

}

void Enemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}

#pragma region
float Enemy::getHealth() const
{
    return health;
}

int Enemy::getDamage() const
{
    return damage;
}

Vector2f Enemy::getVelocity() const
{
    return velocity;
}

Color Enemy::getColor() const
{
    return color;
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

void Enemy::setDamage(int numSides)
{
    this->damage = numSides;
}

void Enemy::setVelocity(Vector2f velocity)
{
    this->velocity = velocity;
}

void Enemy::setColor(Color color)
{
    this->color = color;
}

void Enemy::setBTree(BehaviorTree* bTree)
{
    this->bTree = bTree;
}
#pragma endregion Setters

/******Private Functions******/
