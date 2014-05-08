#include "Square.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include <iostream>
#include <typeinfo>
#include <string>

Square::Square(Vector2f position)
{
    square = RectangleShape(Vector2f(20.f, 20.f));
    square.setOrigin(10.0f, 10.0f);

    // Set Position
    setPosition(position);

    // Create Box2D body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    mBody = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);

    // Setup Box2D body shape
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f * Game::p2m, 10.0f * Game::p2m);

    // Setup Box2D body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 100.0f;
    fixtureDef.friction = 0.3f;

    // Set Fixture to Box2D body
    mBody->CreateFixture(&fixtureDef);
}

void Square::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(square, states);
}

void Square::onUpdate(Time dt)
{
    //if (Keyboard::isKeyPressed(Keyboard::Num1))
    //{
    //    destroy();
    //}
}

void Square::onFixedUpdate(Time dt)
{
    b2Vec2 position = mBody->GetPosition();
    float angle = mBody->GetAngle();
    Vector2f sPosition(position.x * Game::m2p, Game::yResolution - position.y * Game::m2p);
    setPosition(sPosition);
    setRotation(angle);
}