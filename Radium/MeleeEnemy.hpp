#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Enemy.hpp"

class MeleeEnemy : public Enemy
{
public:
    MeleeEnemy();

protected:
    //virtual void buildBehaviorTree();
    //virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
    //virtual void updateCurrent(Time dt);
};

