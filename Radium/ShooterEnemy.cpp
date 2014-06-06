#include "ShooterEnemy.hpp"
#include "Player.hpp"
#include "GameWorld.hpp"


ShooterEnemy::ShooterEnemy(Vector2f position) : Enemy(position)
{
    mHealth = 200.0f;
    mBTreeFrequency = 2.0f;
    mVelocity = Vector2f(10.0f, 10.0f);
    mColor = Color::Yellow;
    mRectShape.setOrigin(20.0f, 20.0f);
    mRectShape.setFillColor(mColor);
    mBTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(mBTree);

    mGun = addComponent<Gun>();
}

void ShooterEnemy::buildBehaviorTree()
{

}

void ShooterEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
        GameWorld::getInstance()->getPlayer()->takeDamage(mDamage);
    }
}

void ShooterEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}

