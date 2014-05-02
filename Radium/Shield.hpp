#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
using namespace sf;

class Shield : public Entity
{
public:
    Shield(Vector2f position, float lTime);

private:
    virtual void    drawCurrent(RenderTarget& target, RenderStates states) const;
    virtual void    updateCurrent(Time dt);
    virtual void    fixedUpdateCurrent(Time dt);

public:

private:
    RectangleShape shieldObj;
    b2Body* mBody;
    float lifeTime;
    float timer;
    float cooldown;

};