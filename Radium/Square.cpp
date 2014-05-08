#include "Square.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include <iostream>
#include <typeinfo>
#include <string>
#include "SquareRigidbody.hpp"

Square::Square(Vector2f position)
{
    square = RectangleShape(Vector2f(20.f, 20.f));
    square.setOrigin(10.0f, 10.0f);

    // Set Position
    setPosition(position);

    SquareRigidbody* rigidbody = addComponent<SquareRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(square);
}

void Square::onDraw(RenderTarget& target, RenderStates states) const
{
    target.draw(square, states);
}