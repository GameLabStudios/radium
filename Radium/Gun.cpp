#define _USE_MATH_DEFINES
#include <cmath>
#include "Gun.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

Gun::Gun(Entity* entity) : Component(entity)
{
    // Configure firing and cooldown counter
    mFiring = false;
    mCooldownCounter = 0.0f;

    // Default Gun Parameters
    mSpreadAngle = 0.0f;
    mDamage = 20.0f;
    mRecoil = 0.0f;
    mBulletSpeed = 12.0f;
    mArmorPen = 3;
    mCooldown = 0.2f;
}

Gun::Gun(Entity* entity, std::string parameters) : Component(entity)
{
    // Parse Parameters String
    parseParameters(parameters);

    mFiring = false;
    mCooldownCounter = 0.0f;
}

void Gun::onUpdate(sf::Time dt)
{
    handleInput();
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

    if (mFiring && mCooldownCounter == 0.0f)
    {
        fireGun();
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

void Gun::parseParameters(std::string parameters)
{
    // Read in hex values
    unsigned values[6];
    for (int i = 0; i < 6; i++)
    {
        values[i] = std::stoul(parameters.substr(i * 2, 2), nullptr, 16);
    }

    // Calculate float values
    float floatValues[6];
    for (int i = 0; i < 6; i++)
    {
        floatValues[i] = values[i] / 255.0f;
    }

    // Calculate Spread Angle
    mSpreadAngle = 45.0f * floatValues[0];
    std::cout << "Spread: " << mSpreadAngle << std::endl;

    // Calculate Damage
    mDamage = 100.0f * floatValues[1];
    std::cout << "Damage: " << mDamage << std::endl;

    // Calculate Recoil
    mRecoil = 40.0f * floatValues[2];
    std::cout << "Recoil: " << mRecoil << std::endl;

    // Calculate Bullet Speed
    mBulletSpeed = 30.0f * floatValues[3] + 10.0f;
    std::cout << "Bullet Speed: " << mBulletSpeed << std::endl;

    // Calculate Armor Pen
    mArmorPen = (unsigned)ceil(5.0f * floatValues[4]);
    std::cout << "Armor Pen: " << mArmorPen << std::endl;

    // Calculate Cooldown
    mCooldown = 1.0f * floatValues[5];
    std::cout << "Cooldown: " << mCooldown << std::endl;
}

void Gun::equipGun()
{
    // Create all Bullets
    for (unsigned i = 0; i < 10; i++)
    {
        mBullets.push_back(new Bullet(mDamage));
    }
}

void Gun::unEquipGun()
{
    // Destory all bullets
    for (unsigned i = 0; i < 10; i++)
    {
        mBullets[i]->destroy();
    }
    // Clear pointers from vector
    mBullets.clear();
}

float Gun::getSpreadAngle() const
{
    return mSpreadAngle;
}

float Gun::getDamage() const
{
    return mDamage;
}

float Gun::getRecoil() const
{
    return mRecoil;
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

void Gun::fireGun()
{
    // If there are unused bullets
    if (mUsedBullets < mBullets.size())
    {
        // Set Cooldown Counter
        mCooldownCounter = mCooldown;

        float angle = GameWorld::getInstance()->getPlayer()->getRotation();
        sf::Vector2f direction(cos((float)(angle * M_PI) / 180.0f), sin((float)(angle * M_PI) / 180.0f));

        // Get Bullet from Vector
        Bullet* newBullet = mBullets[mUsedBullets];
        newBullet->rigidbody->body->SetActive(true);
        mUsedBullets++;

        // Set Bullet Transform
        sf::Vector2f spawnPosition = mEntity->getPosition() + direction * 30.0f;
        newBullet->rigidbody->body->SetTransform(b2Vec2(spawnPosition.x * Game::p2m, spawnPosition.y * Game::p2m), (float)(angle * M_PI) / 180.0f);

        // Set Bullet Velocity
        b2Vec2 velocity(direction.x * mBulletSpeed, direction.y * mBulletSpeed);
        newBullet->rigidbody->body->SetLinearVelocity(velocity);

        // Add Bullet to Scene
        GameWorld::getInstance()->attachChildToNode(GameWorld::getInstance()->getPlayer()->getParent(), SceneNode::Ptr(newBullet));
    }
}