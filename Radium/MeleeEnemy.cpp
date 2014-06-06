#include "MeleeEnemy.hpp"
#include "ChasePlayer.hpp"
#include "Player.hpp"

MeleeEnemy::MeleeEnemy(Vector2f position) : Enemy(position)
{
    mHealth = 100.0f;
    mDamage = 20.0f;
    mBTreeFrequency = 4.0f;
    mVelocity = Vector2f(12.0f, 12.0f);
    mColor = Color::Red;
    mRectShape.setOrigin(20.0f, 20.0f);
    mRectShape.setFillColor(mColor);
    mBTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(mBTree);
}

void MeleeEnemy::buildBehaviorTree()
{
    ChasePlayer* chase = new ChasePlayer(mBTree, this);
    mBTree->setRootNode(chase);
    mBTree->setUpdateFrequency(mBTreeFrequency);
}

void MeleeEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
        GameWorld::getInstance()->getPlayer()->takeDamage(mDamage);
    }
}

void MeleeEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}