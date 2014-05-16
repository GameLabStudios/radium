#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Component.hpp"
#include "Player.hpp"

class ShieldRigidbody : public Component
{


public:
                    ShieldRigidbody(Entity* entity);
    void            setShape(RectangleShape shape);
    virtual void    onFixedUpdate(sf::Time dt);

public:
    b2Body* body;
};