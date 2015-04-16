#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Enemy.hpp"
#include "Gun.hpp"

class AgileShooter : public Enemy
{
public:
    AgileShooter(Vector2f position);
};

