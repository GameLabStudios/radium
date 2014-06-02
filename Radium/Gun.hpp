#pragma once
#include <stack>
#include <string>
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "Bullet.hpp"

class Gun : public Component
{
public:
                                        Gun(Entity* entity);
                                        Gun(Entity* entity, std::string parameters);
    void                                parseParameters(std::string parameters);
    void                                equipGun();
    void                                unEquipGun();

    // Getters
    float                               getSpreadAngle() const;
    float                               getDamage() const;
    float                               getRecoil() const;
    float                               getBulletSpeed() const;
    unsigned                            getArmorPen() const;
    float                               getCooldown() const;
    bool                                getFiring() const;

private:
    virtual void                        onUpdate(sf::Time dt);
    virtual void                        onFixedUpdate(sf::Time dt);
    virtual void                        fireGun();
    void                                handleInput();

private:
    float                               mSpreadAngle;
    float                               mDamage;
    float                               mRecoil;
    float                               mBulletSpeed;
    unsigned                            mArmorPen;
    float                               mCooldown;
    bool                                mFiring;
    float                               mCooldownCounter;

    std::vector<Bullet*>                mBullets;
    unsigned                            mUsedBullets;
};