#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"

using namespace sf;

class Square : public Entity
{
public:
    Square(Vector2f position);

private:
    virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
    virtual void updateCurrent(Time dt);
    virtual void fixedUpdateCurrent(Time dt);

private:
    RectangleShape square;
    b2Body* mBody;
};