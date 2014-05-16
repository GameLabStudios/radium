#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Player.hpp"

using namespace sf;

class Shield : public Entity
{
public:
    Shield(Vector2f position, float lTime);

private:
    virtual void    onDraw(RenderTarget& target, RenderStates states) const;
    virtual void    onUpdate(Time dt);
    virtual void    onFixedUpdate(Time dt);

private:
    RectangleShape shieldObj;
    b2Body* mBody;
    float lifeTime;
    float timer;
    float cooldown;
};