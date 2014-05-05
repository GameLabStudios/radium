#define _USE_MATH_DEFINES

#include "Shield.hpp"
#include <iostream>
#include "GameWorld.hpp"
#include "Game.hpp"
#include <math.h>

Shield::Shield(Vector2f position, float lTime)
{
    lifeTime = lTime;

    shieldObj = RectangleShape(Vector2f(20.f, 20.f));
    shieldObj.setOrigin(10.0f, 10.0f);

    // Set Position
    setPosition(position + Vector2f(20.0f, 0.0f));

    // Create Box2D body
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    mBody = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);

    // Setup Box2D body shape
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f * Game::p2m, 10.0f * Game::p2m);

    // Setup Box2D body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    // Set Fixture to Box2D body
    mBody->CreateFixture(&fixtureDef);
}

void Shield::onUpdate(Time dt)
{

}

void Shield::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(shieldObj, states);
}

void Shield::onFixedUpdate(Time dt)
{
    b2Vec2 position = mBody->GetPosition();
    float angle = mBody->GetAngle();
    Vector2f sPosition(position.x * Game::m2p, Game::yResolution - position.y * Game::m2p);
    setPosition(sPosition);
    setRotation(angle);
}