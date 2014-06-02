#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Rigidbody.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

Rigidbody::Rigidbody(Entity* entity) : Component(entity)
{
    // Rigidbodies update rotation by default
    mCanRotate = true;

    // Set entity pointer shortcut
    mEntity->rigidbody = this;
}

Rigidbody::~Rigidbody()
{
    GameWorld::getInstance()->getb2World()->DestroyBody(body);
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

    bodyDef.position.Set(position.x * Game::p2m, position.y * Game::p2m);
    body = GameWorld::getInstance()->getb2World()->CreateBody(&bodyDef);

    // Store reference to entity in body
    body->SetUserData(mEntity);
}

void Rigidbody::canRotate(bool canRotate)
{
    mCanRotate = canRotate;
}

void Rigidbody::onFixedUpdate(sf::Time dt)
{
    // note parent doesn't necessarily have a body
    // therefore process of conversion requires this body's position to be in world coordinates


    // position in meters
    b2Vec2 mPosition = body->GetPosition();

    // pPosition holds the world pixel coordinates of this
    Vector2f pPhysicsPosition(mPosition.x * Game::m2p, mPosition.y * Game::m2p);

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
    
    // Update rotation if canRotate flag is set
    if (mCanRotate)
    {
        float angle = body->GetAngle();
        mEntity->setRotation((angle * 180.0f) / M_PI);
    }
}