#include "Rigidbody.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

Rigidbody::Rigidbody(Entity* entity) : Component(entity)
{
    // Set entity pointer shortcut
    mEntity->rigidbody = this;
}

void Rigidbody::createBody(type bodyType)
{
    // Get Graphics Position
    sf::Vector2f position = mEntity->getPosition();

    // Create Box2D Body
    b2BodyDef bodyDef;
    if (bodyType == dynamicBody)
    {
        bodyDef.type = b2_dynamicBody;
    }
    else if (bodyType = staticBody)
    {
        bodyDef.type = b2_staticBody;
    }
    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    body = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);
}

void Rigidbody::onFixedUpdate(sf::Time dt)
{
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    Vector2f sPosition(position.x * Game::m2p, Game::yResolution - position.y * Game::m2p);
    mEntity->setPosition(sPosition);
    mEntity->setRotation(angle);
}