#include "SquareRigidbody.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

SquareRigidbody::SquareRigidbody(Entity* entity) : Rigidbody(entity)
{
}

void SquareRigidbody::setShape(RectangleShape shape)
{
    // Get shape size
    sf::Vector2f size = shape.getSize();

    // Setup Bod2D body shape
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox((size.x * Game::p2m) / 2.0f, (size.y * Game::p2m) / 2.0f);

    // Setup Box2D body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 100.0f;
    fixtureDef.friction = 0.3f;

    // Set Fixture to Box2D body
    body->CreateFixture(&fixtureDef);
}

