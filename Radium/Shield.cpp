#define _USE_MATH_DEFINES

#include "Shield.hpp"
#include <iostream>
#include "GameWorld.hpp"
#include "Game.hpp"
#include "ShieldRigidbody.hpp"

Shield::Shield(Vector2f position, float lTime)
{
    lifeTime = lTime;

    shieldObj = RectangleShape(Vector2f(20.f, 20.f));
    shieldObj.setOrigin(10.0f, 10.0f);
    shieldObj.setFillColor(Color::Blue);

    // Set Position
    setPosition(position * Game::m2p);

    ShieldRigidbody* rigidbody = addComponent<ShieldRigidbody>();
    rigidbody->createBody(Rigidbody::staticBody);
    rigidbody->setShape(shieldObj);
}

void Shield::onUpdate(Time dt)
{
    //std::cout << "World pos: " << getWorldPosition().x << ", " << getWorldPosition().y << std::endl;
    //std::cout << "rot: " << GameWorld::getInstance()->getPlayer()->getRotation() << std::endl;
    ShieldRigidbody* shield = getComponent<ShieldRigidbody>();
    b2Vec2 physicsPosition = b2Vec2(getWorldPosition().x * Game::p2m, getWorldPosition().y * Game::p2m);
    shield->body->SetTransform(physicsPosition, (M_PI * GameWorld::getInstance()->getPlayer()->getRotation()) / 180.0f );//GameWorld::getInstance()->getPlayer()->getRotation());
}

void Shield::onDraw(RenderTarget& target, RenderStates states) const
{
    //std::cout << "pos: " << getPosition().x << ", "<< getPosition().y <<std::endl;
    target.draw(shieldObj, states);
}

void Shield::onBeginContact(b2Contact* contact)
{
    std::cout << "shield hit!\n";
}