#define _USE_MATH_DEFINES
#include "Enemy.hpp"
#include "Game.hpp"
#include "SquareRigidbody.hpp"
#include "Bullet.hpp"
#include "GameWorld.hpp"
#include "CollisionFilters.hpp"
#include <cmath>

Enemy::Enemy(Vector2f position)
{
    mRectShape = RectangleShape(Vector2f(40.0f, 40.0f));
    
    mLine = RectangleShape(Vector2f(20.0f, 5.0f));
    mLine.setOrigin(10.0f, 2.5f);
    mLine.setPosition(mLine.getPosition() + Vector2f(10.0f, 0.0f));

    mPlayer = GameWorld::getInstance()->getPlayer();

    //set position
    setPosition(position);

    SquareRigidbody* rigidbody = addComponent<SquareRigidbody>();
    rigidbody->setBits(Collision::ENEMIES, ~Collision::ENEMY_BULLETS);
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(mRectShape);
}

/******Public Functions******/

void Enemy::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(mRectShape, states);
    target.draw(mLine, states);
}

void Enemy::onUpdate(Time dt)
{
    Vector2f playerPosition = mPlayer->getPosition();

    float angle = atan2(playerPosition.y - getPosition().y, playerPosition.x - getPosition().x);
    setRotation((float)((angle*180.0f) / M_PI));
    rigidbody->body->SetTransform(rigidbody->body->GetPosition(), angle);

    getBTree()->update(dt);
    if (mHealth <= 0)
    {
        destroy();
    }
}

void Enemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{

}

void Enemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}

void Enemy::takeDamage(float damage)
{
    mHealth -= damage;
}

#pragma region
float Enemy::getHealth() const
{
    return mHealth;
}

int Enemy::getDamage() const
{
    return mDamage;
}

Vector2f Enemy::getVelocity() const
{
    return mVelocity;
}

Color Enemy::getColor() const
{
    return mColor;
}

BehaviorTree* Enemy::getBTree() const
{
    return mBTree;
}
#pragma endregion Getters

/******Protected Functions******/

#pragma region
void Enemy::setHealth(float health)
{
    this->mHealth = health;
}

void Enemy::setDamage(int numSides)
{
    this->mDamage = numSides;
}

void Enemy::setVelocity(Vector2f velocity)
{
    this->mVelocity = velocity;
}

void Enemy::setColor(Color color)
{
    this->mColor = color;
}

void Enemy::setBTree(BehaviorTree* bTree)
{
    this->mBTree = bTree;
}
#pragma endregion Setters

/******Private Functions******/
