#include "MouseTest.hpp"
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

MouseTest::MouseTest()
{
    circle = CircleShape(20, 30);
    circle.setOrigin(20.f, 20.f);
    playerSpeed = 200.0f;
}

void MouseTest::drawCurrent(RenderTarget& target, RenderStates states) const
{
    target.draw(circle, states);
}

void MouseTest::updateCurrent(Time dt)
{
    //Vector2f mousePos = Game::getInstance().getWorld().getMousePosition();

    //float angle = atan2(mousePos.y - getPosition().y, mousePos.x - getPosition().x);
    //setRotation(((angle * 180) / M_PI) - 45.f);

    //direction of movement
    Vector2f direction = Vector2f(0.0f, 0.0f);

    //input
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        direction.x -= 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        direction.x += 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        direction.y += 1.0f;
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        direction.y -= 1.0f;
    }

    //normalize the direction
    if (direction.x != 0.0f)
    {
        direction.x = direction.x / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }
    if (direction.y != 0.0f)
    {
        direction.y = direction.y / sqrt((direction.x*direction.x) + (direction.y*direction.y));
    }

    //move the player
    move(direction * playerSpeed * dt.asSeconds());
}