#define _USE_MATH_DEFINES

#include "Shield.hpp"
#include <iostream>
#include "GameWorld.hpp"
#include "Game.hpp"
#include "SquareRigidbody.hpp"

Shield::Shield(Vector2f position, float lTime)
{
    lifeTime = lTime;

    shieldObj = RectangleShape(Vector2f(20.f, 20.f));
    shieldObj.setOrigin(10.0f, 10.0f);
    shieldObj.setFillColor(Color::Blue);

    // Set Position
    setPosition(position);

    SquareRigidbody* rigidbody = addComponent<SquareRigidbody>();
    rigidbody->createBody(Rigidbody::staticBody);
    rigidbody->setShape(shieldObj);
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
}