#include "MeleeEnemy.hpp"
#include "ChasePlayer.hpp"
#include "Player.hpp"

MeleeEnemy::MeleeEnemy(Vector2f position) : Enemy(position)
{
    health = 100.0f;
    damage = 20.0f;
    velocity = Vector2f(12.0f, 12.0f);
    color = Color::Red;
    rectShape.setOrigin(20.0f, 20.0f);
    rectShape.setFillColor(color);
    bTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(bTree);
}

void MeleeEnemy::buildBehaviorTree()
{
    ChasePlayer* chase = new ChasePlayer(bTree, this);
    bTree->setRootNode(chase);
}

void MeleeEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
        GameWorld::getInstance()->getPlayer()->takeDamage(damage);
    }
}

void MeleeEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}