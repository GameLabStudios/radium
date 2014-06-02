#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Component.hpp"
#include "Player.hpp"
#include "SquareRigidbody.hpp"

class ShieldRigidbody : public SquareRigidbody
{
public:
                    ShieldRigidbody(Entity* entity);
    void            onFixedUpdate(sf::Time dt);
};