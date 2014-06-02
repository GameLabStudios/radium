#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bullet : public Entity
{
public:
    Bullet(sf::Vector2f position, sf::Vector2f velocity);
    virtual void onUpdate(sf::Time dt);
    virtual void onDraw(RenderTarget& target, RenderStates states) const;
    virtual void onBeginContact(b2Fixture* other, b2Contact* contact);

private:
    CircleShape circle;
    b2Vec2 mVelocity;
    float mLifetime;
};