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
    void                                randomizeGun();

    // Getters
    float                               getSpreadAngle() const;
    float                               getDamage() const;
    float                               getRecoil() const;
    float                               getBulletSpeed() const;
    unsigned                            getArmorPen() const;
    float                               getCooldown() const;
    bool                                getBurst() const;
    float                               getBurstAmount() const;
    bool                                getFiring() const;
    void                                removeBullet(Bullet* bullet);

    void                                createGun(float, float, float, float, float, bool, float);
    void                                setFiring(bool firing);
    void                                setPlayerControlled(bool playerControlled);
    void                                setEnemyOwned(bool enemyOwned);

private:
    virtual void                        onUpdate(sf::Time dt);
    virtual void                        onFixedUpdate(sf::Time dt);
    virtual void                        fireGun();
    void                                handleInput();
    void                                updateBullets();

private:
    float                               mSpreadAngle;
    float                               mDamage;
    float                               mBulletSpeed;
    float                               mBulletLife;
    unsigned                            mArmorPen;

    bool                                mBurst;
    unsigned                            mBurstAmount;

    float                               mCooldown;
    bool                                mFiring;
    float                               mCooldownCounter;

    std::vector<Bullet*>                mBullets;
    unsigned                            mUsedBullets;

    bool                                mPlayerControlled;
    bool                                mEnemyOwned;
};