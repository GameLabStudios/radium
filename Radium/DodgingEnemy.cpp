#include "DodgingEnemy.hpp"
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Selector.hpp"
#include "Sequence.hpp"
#include "IsNearPlayer.hpp"
#include "IsPlayerShooting.hpp"
#include "ChasePlayer.hpp"
#include "DodgeBullets.hpp"


DodgingEnemy::DodgingEnemy(Vector2f position) : Enemy(position)
{
    mHealth = 80.0f;
    mDamage = 30.0f;
    mBTreeFrequency = 0.5f;
    mVelocity = Vector2f(5.0f, 5.0f);
    mColor = Color::Blue;
    mRectShape.setOrigin(20.0f, 20.0f);
    mRectShape.setFillColor(mColor);
    mBTree = new BehaviorTree();
    buildBehaviorTree();
    setBTree(mBTree);
}

void DodgingEnemy::buildBehaviorTree()
{
    Selector* topSelector = new Selector();
    Sequence* dodgeSequence = new Sequence();
    IsNearPlayer* nearPlayer = new IsNearPlayer(mBTree, this);
    IsPlayerShooting* playerShooting = new IsPlayerShooting(mBTree, this);
    DodgeBullets* dodge = new DodgeBullets(mBTree, this);
    ChasePlayer* chase = new ChasePlayer(mBTree, this);

    topSelector->addChild(dodgeSequence);
    topSelector->addChild(chase);

    dodgeSequence->addChild(nearPlayer);
    dodgeSequence->addChild(playerShooting);
    dodgeSequence->addChild(dodge);

    mBTree->setRootNode(topSelector);
    mBTree->setUpdateFrequency(mBTreeFrequency);
}

void DodgingEnemy::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    Entity* entityPtr = static_cast<Entity*>(other->GetBody()->GetUserData());
    Player* playerPtr = dynamic_cast<Player*>(entityPtr);
    if (playerPtr != nullptr)
    {
        destroy();
        GameWorld::getInstance()->getPlayer()->takeDamage(mDamage);
    }
}

void DodgingEnemy::onEndContact(b2Fixture* other, b2Contact* contact)
{

}