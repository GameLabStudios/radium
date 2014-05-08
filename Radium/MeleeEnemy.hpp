#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Enemy.hpp"

class MeleeEnemy : public Enemy
{
public:
    MeleeEnemy(Vector2f position);
};

