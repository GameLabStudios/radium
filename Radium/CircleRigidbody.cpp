#include "CircleRigidbody.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

CircleRigidbody::CircleRigidbody(Entity* entity) : Rigidbody(entity)
{
}

void CircleRigidbody::setShape(CircleShape shape)
{
    // Get shape size
    float radius = shape.getRadius();

    // Setup Box2D body shape
    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = radius * Game::p2m;

    // Setup Box2D body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicCircle;
    fixtureDef.density = 1.0f;
    fixtureDef.filter.categoryBits = mCategoryBits;
    fixtureDef.filter.maskBits = mMaskBits;
    body->CreateFixture(&fixtureDef);
}