#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "BehaviorTree.hpp"
#include "Composite.hpp"
#include "Sequence.hpp"
#include "Selector.hpp"
#include "MoveAction.hpp"
#include "NearPlayerCondition.hpp"
#include "PlayerShootingCondition.hpp"
#include "DodgeShotsAction.hpp"
#include "AttackPlayerAction.hpp"

using namespace sf;
using namespace AI;

class Enemy : public Entity
{
public:
    Enemy();
    inline virtual float     getSpeed() const;

protected:
    virtual void             BuildBehaviorTree();

private:
    virtual void             drawCurrent(RenderTarget& target, RenderStates states) const;
    virtual void             updateCurrent(Time dt);
    inline virtual void      setSpeed(float);

private:
    RectangleShape           rectangle;
    float                    enemySpeed = 1.0f;
    float                    health;
    float                    updateTimer = 0.0f;
    float                    timeTilNextUpdate = 4.0f;
    BehaviorTree*            bTree;
    Sequence*                rootSequence;
    MoveAction*              moving;
    Selector*                selection;
    Sequence*                dodgeSequence;
    NearPlayerCondition*     nearby;
    PlayerShootingCondition* shooting;
    DodgeShotsAction*        dodge;
    Sequence*                attackSequence;
    AttackPlayerAction*      attacking;
};

