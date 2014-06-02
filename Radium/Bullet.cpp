#include "Bullet.hpp"
#include "Enemy.hpp"
#include "CircleRigidbody.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity) : Entity(), mLifetime(1.0f)
{
    // Set mVelocity
    mVelocity = b2Vec2(velocity.x, velocity.y);

    // SFML Circle Object
    circle = CircleShape(5.0f, 10.0f);
    circle.setOrigin(5.0f, 5.0f);
    circle.setFillColor(Color::Magenta);

    // Set Position
    setPosition(position);

    // Rigidbody Component
    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);

    // Set Velocity
    rigidbody->body->SetLinearVelocity(mVelocity);
}

void Bullet::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(circle, states);
}

void Bullet::onUpdate(sf::Time dt)
{
    mLifetime -= dt.asSeconds();
    if (mLifetime <= 0.0f)
    {
        destroy();
    }
}

void Bullet::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Enemy* enemyPtr = dynamic_cast<Enemy*>(entityPtr);
    if (enemyPtr != nullptr)
    {
        enemyPtr->takeDamage(10.0f);
    }
    destroy();
}