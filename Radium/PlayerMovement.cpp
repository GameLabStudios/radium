#include "PlayerMovement.hpp"
#include "CircleRigidbody.hpp"

PlayerMovement::PlayerMovement(Entity* entity) : Component(entity)
{
    playerSpeed = 10.0f;
}

void PlayerMovement::onUpdate(sf::Time dt)
{
    // Direction of movement
    direction = Vector2f(0.0f, 0.0f);

    // Input
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        direction.x -= 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        direction.x += 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        direction.y -= 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        direction.y += 1.0f;
    }

    // Normalize the direction
    if (direction.x != 0.0f)
    {
        direction.x = direction.x / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }
    if (direction.y != 0.0f)
    {
        direction.y = direction.y / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }
}

void PlayerMovement::onFixedUpdate(sf::Time dt)
{
    // Move player
    b2Vec2 pushDirection = b2Vec2(direction.x * playerSpeed, direction.y * -1.f * playerSpeed);
    if (pushDirection == b2Vec2_zero)
    {
        mEntity->rigidbody->body->SetLinearVelocity(b2Vec2_zero);
    }
    else
    {
        mEntity->rigidbody->body->SetLinearVelocity(pushDirection);
    }
}