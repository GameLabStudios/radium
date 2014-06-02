#include "DodgingEnemy.hpp"
#include "Player.hpp"
#include "GameWorld.hpp"


DodgingEnemy::DodgingEnemy(Vector2f position) : Enemy(position)
{
    health = 80.0f;
    damage = 30.0f;
    velocity = Vector2f(9.0f, 9.0f);
    color = Color::Blue;
    rectShape.setOrigin(20.0f, 20.0f);
    rectShape.setFillColor(color);
    bTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(bTree);
}

void DodgingEnemy::buildBehaviorTree()
{

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