#include "Entity.hpp"

void Entity::setVelocity(Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

Vector2f Entity::getVelocity() const
{
    return mVelocity;
}