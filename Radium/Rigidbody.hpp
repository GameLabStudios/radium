#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Component.hpp"


class Rigidbody : public Component
{
public:
    enum type { dynamicBody, staticBody };

public:
                    Rigidbody(Entity* entity);
    void            createBody(type bodyType);
    virtual void    onFixedUpdate(sf::Time dt);

public:
    b2Body* body;
    b2BodyDef bodyDef;
};