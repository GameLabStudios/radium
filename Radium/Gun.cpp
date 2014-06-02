#define _USE_MATH_DEFINES
#include <cmath>
#include "Gun.hpp"
#include "GameWorld.hpp"

Gun::Gun(Entity* entity) : Component(entity), mCooldown(0.2f)
{
    mFiring = false;
    
    mMaxAmmo = 40;
    mAmmo = mMaxAmmo;
    mCooldownCounter = 0.0f;
}

void Gun::onUpdate(sf::Time dt)
{
    handleInput();
}

void Gun::onFixedUpdate(sf::Time dt)
{
    if (mFiring)
    {
        mCooldownCounter += dt.asSeconds();
        if (mCooldownCounter >= mCooldown)
        {
            mCooldownCounter -= mCooldown;
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
            std::cout << "Now Firing!\n";
        }
    }
    else
    {
        if (mFiring)
        {
            mFiring = false;
            mCooldownCounter = 0.0f;
            std::cout << "Done Firing!\n";
        }
    }
}

void Gun::fireGun()
{
    float angle = GameWorld::getInstance()->getPlayer()->getRotation();
    std::cout << angle << std::endl;
    sf::Vector2f direction(cos((angle * M_PI) / 180.0f), sin((angle * M_PI) / 180.0f));
    
    std::unique_ptr<Entity> newBullet(new Bullet(mEntity->getPosition() + (direction * 30.0f), (direction * 12.0f)));
    GameWorld::getInstance()->attachChildToNode(GameWorld::getInstance()->getPlayer()->getParent(), std::move(newBullet));
}