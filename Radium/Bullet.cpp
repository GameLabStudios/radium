#include "Bullet.hpp"
#include "Enemy.hpp"
#include "CircleRigidbody.hpp"
#include "Gun.hpp"
#include "GameWorld.hpp"
#include "CollisionFilters.hpp"

Bullet::Bullet(float damage)
{
    // Set Damage
    mDamage = damage;

    // SFML Circle Object
    circle = CircleShape(2.0f, 10);
    circle.setOrigin(2.0f, 2.0f);
    circle.setFillColor(Color::Magenta);
}

void Bullet::makeRigidBody()
{
    // Rigidbody Component
    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->setBits(Collision::PLAYER_BULLETS, ~Collision::PLAYER_BULLETS ^ Collision::SHIELD);
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);
    rigidbody->body->SetBullet(true);
}

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity, float damage) : Entity(), mLifetime(1.0f)
{
    // Set mVelocity
    mVelocity = b2Vec2(velocity.x, velocity.y);

    // Set Damage
    mDamage = damage;

    // SFML Circle Object
    circle = CircleShape(2.0f, 10);
    circle.setOrigin(2.0f, 2.0f);
    circle.setFillColor(Color::Magenta);

    // Set Position
    setPosition(position);

    // Rigidbody Component
    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);
    rigidbody->body->SetBullet(true);

    // Set Velocity
    rigidbody->body->SetLinearVelocity(mVelocity);
}

void Bullet::setLifetime(float time)
{
    mLifetime = time;
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
        enemyPtr->takeDamage(mDamage);
    }

    destroy();
}