#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "Bullet.hpp"

class Gun : public Component
{
public:
                        Gun(Entity* entity);

private:
    virtual void        onUpdate(sf::Time dt);
    virtual void        onFixedUpdate(sf::Time dt);
    void                handleInput();
    void                fireGun();

private:
    std::vector<Bullet> mBullets;
    bool                mFiring;

    unsigned            mMaxAmmo;
    unsigned            mAmmo;
    const float         mCooldown;
    float               mCooldownCounter;
};