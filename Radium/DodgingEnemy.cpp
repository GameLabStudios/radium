#include "DodgingEnemy.hpp"
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Selector.hpp"
#include "Sequence.hpp"
#include "IsPlayerShooting.hpp"
#include "ChasePlayer.hpp"
#include "DodgeBullets.hpp"


DodgingEnemy::DodgingEnemy(Vector2f position) : Enemy(position)
{
    health = 80.0f;
    damage = 30.0f;
    velocity = Vector2f(5.0f, 5.0f);
    color = Color::Blue;
    rectShape.setOrigin(20.0f, 20.0f);
    rectShape.setFillColor(color);
    bTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(bTree);
}

void DodgingEnemy::buildBehaviorTree()
{
    Selector* topSelector = new Selector();
    Sequence* dodgeSequence = new Sequence();
    IsPlayerShooting* playerShooting = new IsPlayerShooting(bTree, this);
    DodgeBullets* dodge = new DodgeBullets(bTree, this);
    ChasePlayer* chase = new ChasePlayer(bTree, this);

    topSelector->addChild(dodgeSequence);
    topSelector->addChild(chase);

    dodgeSequence->addChild(playerShooting);
    dodgeSequence->addChild(dodge);

    bTree->setRootNode(topSelector);
}

void DodgingEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
        GameWorld::getInstance()->getPlayer()->takeDamage(damage);
    }
}

void DodgingEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}