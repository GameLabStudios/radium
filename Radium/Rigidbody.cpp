#include <math.h>

#define _USE_MATH_DEFINES

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
    sf::Vector2f position = mEntity->getWorldPosition();

    // Create Box2D Body
    bodyDef;
    if (bodyType == dynamicBody)
    {
        bodyDef.type = b2_dynamicBody;
    }
    else if (bodyType == staticBody)
    {
        bodyDef.type = b2_staticBody;
    }

    std::cout << "world pos: " << position.x << ", " << position.y << std::endl;
    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    body = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);
}

void Rigidbody::onFixedUpdate(sf::Time dt)
{
    // note parent doesn't necessarily have a body
    // therefore process of conversion requires this body's position to be in world coordinates
    float angle = body->GetAngle();

    // position in meters
    b2Vec2 mPosition = body->GetPosition();

    // pPosition holds the world pixel coordinates of this
    Vector2f pPhysicsPosition(mPosition.x * Game::m2p, Game::yResolution - mPosition.y * Game::m2p);

    SceneNode* parent = mEntity->getParent();
    if (parent != nullptr && pPhysicsPosition.x != 640)
    {
        //std::cout << "Phyics World in pixels: " << pPhysicsPosition.x << ", " << pPhysicsPosition.y << std::endl;
        pPhysicsPosition -= parent->getWorldPosition();
        //std::cout << "local: " << pPhysicsPosition.x << ", " << pPhysicsPosition.y << std::endl;
    }
    //std::cout << "physics: " << body->GetPosition().x << ", " << body->GetPosition().y << std::endl;



    // setPosition using pixel coordinates
    // since pPosition is local, must add parent's position
    mEntity->setPosition(pPhysicsPosition);
    mEntity->setRotation((angle * 180.0f) / M_PI);
}