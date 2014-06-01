#include "ShieldRigidbody.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

ShieldRigidbody::ShieldRigidbody(Entity* entity) : Component(entity)
{
    // Get Graphics Position
    sf::Vector2f position = mEntity->getWorldPosition();

    // Create Box2D Body
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;

    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    body = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);
}

void ShieldRigidbody::setShape(RectangleShape shape)
{
    // Get shape size
    sf::Vector2f size = shape.getSize();

    // Setup Bod2D body shape
    b2PolygonShape staticBox;
    staticBox.SetAsBox((size.x * Game::p2m) / 2.0f, (size.y * Game::p2m) / 2.0f);

    // Setup Box2D body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;
    fixtureDef.density = 100.0f;
    fixtureDef.friction = 0.3f;

    // Set Fixture to Box2D body
    body->CreateFixture(&fixtureDef);
}