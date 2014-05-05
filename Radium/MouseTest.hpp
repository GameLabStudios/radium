#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace sf;

class MouseTest : public Entity
{
public:
    MouseTest();

private:
    virtual void onDraw(RenderTarget& target, RenderStates states) const;
    virtual void onUpdate(Time dt);

private:
    CircleShape circle;
    float playerSpeed;
};