#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Component.hpp"

class PlayerMovement : public Component
{
public:
                    PlayerMovement(Entity* entity);
    virtual void    onUpdate(sf::Time dt);
    virtual void    onFixedUpdate(sf::Time dt);

private:
    Vector2f        direction;
    float           playerSpeed;

};