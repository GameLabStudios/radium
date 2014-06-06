#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Gun;

class Bullet : public Entity
{
public:
    Bullet(Gun* gun, float damage);
    void         setLifetime(float time);
    virtual void onUpdate(sf::Time dt);
    virtual void onDraw(RenderTarget& target, RenderStates states) const;
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void onDestroy();

private:
    CircleShape circle;
    b2Vec2 mVelocity;
    float mLifetime;
    float mDamage;
    Gun* mGun;
};