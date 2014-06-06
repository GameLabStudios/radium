#define _USE_MATH_DEFINES
#include <cmath>
#include "Gun.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"
#include "EnemyBullet.hpp"

Gun::Gun(Entity* entity) : Component(entity)
{
    // Configure firing and cooldown counter
    mFiring = false;
    mCooldownCounter = 0.0f;

    // Default Gun Parameters
    mBurst = true;
    mBurstAmount = 20;

    mSpreadAngle = 30.0f;
    mDamage = 20.0f;
    mBulletSpeed = 10.0f;
    mBulletLife = 2.0f;
    mArmorPen = 3;
    mCooldown = 0.5f;
}

void Gun::onUpdate(sf::Time dt)
{
    if (mPlayerControlled)
    {
        handleInput();
    }
}

void Gun::onFixedUpdate(sf::Time dt)
{
    // Decrement Cooldown
    if (mCooldownCounter > 0.0f)
    {
        mCooldownCounter -= dt.asSeconds();
        if (mCooldownCounter < 0.0f)
        {
            mCooldownCounter = 0.0f;
        }
    }

    // Check if gun is firinga and ready to fire.
    if (mFiring && mCooldownCounter == 0.0f)
    {
        // If gun is bursty
        if (mBurst)
        {
            // then fire the gun multiple times.
            for (unsigned i = 0; i < mBurstAmount; i++)
            {
                fireGun();
            }
        }
        // Else just fire once.
        else
        {
            fireGun();
        }
    }
}

void Gun::handleInput()
{
    // Check for left mouse click
    if (Mouse::isButtonPressed(Mouse::Button::Left))
    {
        if (!mFiring)
        {
            mFiring = true;
        }
    }
    else
    {
        if (mFiring)
        {
            mFiring = false;
        }
    }
}

void Gun::randomizeGun()
{
    // Calculate random float values
    float floatValues[7];
    for (int i = 0; i < 7; i++)
    {
        floatValues[i] = ((float)rand() / RAND_MAX);
    }

    // Determine if burst
    if (floatValues[5] < 0.4f)
    {
        mBurst = true;
    }
    else
    {
        mBurst = false;
    }
    std::cout << "Burst: " << ((mBurst) ? "true" : "false") << std::endl;

    // Calculate Spread Angle
    mSpreadAngle = 45.0f * floatValues[0];
    std::cout << "Spread: " << mSpreadAngle << std::endl;

    // Calculate Damage
    mDamage = 100.0f * floatValues[1];
    std::cout << "Damage: " << mDamage << std::endl;

    // Calculate Bullet Speed
    mBulletSpeed = 30.0f * floatValues[2] + 10.0f;
    std::cout << "Bullet Speed: " << mBulletSpeed << std::endl;

    // Calculate Armor Pen
    mArmorPen = (unsigned)ceil(5.0f * floatValues[3]);
    std::cout << "Armor Pen: " << mArmorPen << std::endl;

    // Calculate Cooldown
    mCooldown = 1.0f * floatValues[4];
    std::cout << "Cooldown: " << mCooldown << std::endl;

    // Calculate Burst Amount
    if (mBurst)
    {
        // Value between 10 and 40
        mBurstAmount = ceil(floatValues[6] * 30) + 10;
        std::cout << "Burst Amount: " << mBurstAmount << std::endl;
    }
}

float Gun::getSpreadAngle() const
{
    return mSpreadAngle;
}

float Gun::getDamage() const
{
    return mDamage;
}

float Gun::getBulletSpeed() const
{
    return mBulletSpeed;
}

unsigned Gun::getArmorPen() const
{
    return mArmorPen;
}

float Gun::getCooldown() const
{
    return mCooldown;
}

bool Gun::getFiring() const
{
    return mFiring;
}

void Gun::setFiring(bool firing)
{
    mFiring = firing;
}

void Gun::setPlayerControlled(bool playerControlled)
{
    mPlayerControlled = playerControlled;
}

void Gun::setEnemyOwned(bool enemyOwned)
{
    mEnemyOwned = enemyOwned;
}

void Gun::fireGun()
{
    // If there are unused bullets
    if (mUsedBullets < 1000)
    {
        // Set Cooldown Counter
        mCooldownCounter = mCooldown;

        // Get entity angle
        float angle = mEntity->getRotation();
        
        // Add Spread
        angle += (((float)rand() / RAND_MAX) * mSpreadAngle) - mSpreadAngle / 2.0f;

        // Calculate direction
        sf::Vector2f direction(cos((float)(angle * M_PI) / 180.0f), sin((float)(angle * M_PI) / 180.0f));

        // Create a new Bullet
        Bullet* newBullet;
        if (mEnemyOwned)
        {
            newBullet = new EnemyBullet(mDamage);
        }
        else
        {
            newBullet = new Bullet(mDamage);
        }

        //TODO: Make Rigidbody, p.s. This is really fucking stupid
        newBullet->makeRigidBody();
        
        // Set Bullet Lifetime
        newBullet->setLifetime(mBulletLife);

        // Set Bullet Transform
        sf::Vector2f spawnPosition = mEntity->getPosition() + direction * 30.0f;
        newBullet->setPosition(spawnPosition);
        newBullet->rigidbody->body->SetTransform(b2Vec2(spawnPosition.x * Game::p2m, spawnPosition.y * Game::p2m), (float)(angle * M_PI) / 180.0f);

        // Set Bullet Velocity
        b2Vec2 velocity(direction.x * mBulletSpeed, direction.y * mBulletSpeed);
        sf::Vector2f velocitySFML(velocity.x, velocity.y);
        newBullet->rigidbody->body->SetLinearVelocity(velocity);

        // Add Bullet to Scene
        GameWorld::getInstance()->attachChildToNode(mEntity->getParent(), SceneNode::Ptr(newBullet));
    }
}