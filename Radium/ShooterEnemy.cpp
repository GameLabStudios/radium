#include "ShooterEnemy.hpp"
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Selector.hpp"
#include "Sequence.hpp"
#include "IsNearPlayer.hpp"
#include "ChasePlayer.hpp"
#include "ShootPlayer.hpp"


ShooterEnemy::ShooterEnemy(Vector2f position) : Enemy(position)
{
    mHealth = 200.0f;
    mBTreeFrequency = 2.0f;
    mVelocity = Vector2f(10.0f, 10.0f);
    mColor = Color::Yellow;
    mRectShape.setOrigin(20.0f, 20.0f);
    mRectShape.setFillColor(mColor);
    mShootRange = 20.0f;

    mBTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(mBTree);

    mGun = addComponent<Gun>();
    mGun->setEnemyOwned(true);
}

void ShooterEnemy::buildBehaviorTree()
{
    Selector* topSelector = new Selector();
    Sequence* sequence = new Sequence();
    IsNearPlayer* inShootRange = new IsNearPlayer(mBTree, this, mShootRange);
    ShootPlayer* shoot = new ShootPlayer(mBTree, this);
    ChasePlayer* chase = new ChasePlayer(mBTree, this, mShootRange);

    topSelector->addChild(sequence);
    topSelector->addChild(chase);

    sequence->addChild(inShootRange);
    sequence->addChild(shoot);
    
    mBTree->setRootNode(topSelector);
    mBTree->setUpdateFrequency(mBTreeFrequency);
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

