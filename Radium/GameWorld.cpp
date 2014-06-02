#include "GameWorld.hpp"
#include "Square.hpp"
#include "Shield.hpp"
#include <iostream>
#include "Enemy.hpp"
#include "SFMLDebugDraw.hpp"
#include "Box2DCallbackManager.hpp"

GameWorld* GameWorld::sGameWorld = nullptr;

GameWorld::GameWorld(RenderWindow& window) : World(window)
{
    sGameWorld = this;

    // Create Box2D World
    mb2World = new b2World(b2Vec2(0.0f, 0.0f));
    
    // Set-up Box2D Debug Drawing and Options
    SFMLDebugDraw* debugDrawInstance = new SFMLDebugDraw(mWindow);
    // Draw Shapes:                             b2Draw::e_shapeBit
    // Draw Joint Connections:                  b2Draw::e_jointBit 
    // Draw Axis-Aligned Bounding Boxes:        b2Draw::e_aabbBit         
    // Draw Broad-Phase Pairs:                  b2Draw::e_pairBit
    // Draw a marker at body Center of Mass:    b2Draw::e_centerOfMassBit
    debugDrawInstance->SetFlags(b2Draw::e_shapeBit);
    mb2World->SetDebugDraw(debugDrawInstance);

    // Set-up Box2D Callbacks
    mb2World->SetContactListener(new Box2DCallbackManager());

    loadTextures();
    buildScene();

    mWorldView.setCenter(Vector2f(0.f, 0.f));
}

GameWorld* GameWorld::getInstance()
{
    return sGameWorld;
}

GameWorld* GameWorld::createInstance(RenderWindow& window)
{
    if (sGameWorld == nullptr)
    {
        new GameWorld(window);
    }

    return sGameWorld;
}

void GameWorld::update(Time dt)
{
    // Camera tracks player
    // TODO: Detach this code from the GameWorld and set-up Camera class possibly, or at least have code within the update loop do this.
    mWorldView.setCenter(mPlayer->getPosition());

    // Attach Objects to Scene Queue
    if (!mParentQueue.empty())
    {
        SceneNode* parent = mParentQueue.front();
        mParentQueue.pop();

        SceneNode::Ptr child = std::move(mChildQueue.front());
        mChildQueue.pop();

        parent->attachChild(std::move(child));
    }

    // Call Base update(dt)
    World::update(dt);
}

void GameWorld::draw()
{
    mWindow.setView(mWorldView);
    if (mDrawDebug)
    {
        mb2World->DrawDebugData();
    }
    else
    {
        mWindow.draw(mSceneGraph);
    }
}

void GameWorld::fixedUpdate(Time dt)
{
    // Call Base fixedUpdate(dt)
    World::fixedUpdate(dt);

    // Update Box2D World
    int32 velocityIterations = 8;
    int32 positionIterations = 3;
    mb2World->Step(dt.asSeconds(), velocityIterations, positionIterations);
}

Player* GameWorld::getPlayer() const
{
    return mPlayer;
}

b2World* GameWorld::getb2World()
{
    return mb2World;
}

void GameWorld::toggleDebugDraw()
{
    mDrawDebug = !mDrawDebug;
}

SceneNode* GameWorld::attachChildToNode(SceneNode* node, SceneNode::Ptr child)
{
    SceneNode* returnPointer = child.get();
    mChildQueue.push(std::move(child));
    mParentQueue.push(node);
    return returnPointer;
}

void GameWorld::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add player to scene
    std::unique_ptr<Player> player(new Player(mSpawnPosition));
    mPlayer = player.get();
    player->setPosition(mSpawnPosition);
    mSceneLayers[Background]->attachChild(std::move(player));

    // Add melee enemy to scene (temporary)
    Vector2f enemySpawnPos = mSpawnPosition + Vector2f(300.0f, 40.0f);
    std::unique_ptr<MeleeEnemy> meleeEnemy(new MeleeEnemy(enemySpawnPos));
    mMeleeEnemy = meleeEnemy.get();
    meleeEnemy->setPosition(enemySpawnPos);
    mSceneLayers[Background]->attachChild(std::move(meleeEnemy));

    // Add dodging enemy to scene (temporary)
    Vector2f dodgeSpawnPos = mSpawnPosition + Vector2f(250.0f, 80.0f);
    std::unique_ptr<DodgingEnemy> dodgingEnemy(new DodgingEnemy(dodgeSpawnPos));
    mDodgingEnemy = dodgingEnemy.get();
    dodgingEnemy->setPosition(dodgeSpawnPos);
    mSceneLayers[Background]->attachChild(std::move(dodgingEnemy));

    // Add Square to scene on mouseTest
    //std::unique_ptr<Square> square2(new Square());
    //mPlayer->attachChild(std::move(square2));

    // Add Square to scene
    std::unique_ptr<Square> square(new Square(mSpawnPosition + Vector2f(150.0f, 20.0f)));
    mSceneLayers[Foreground]->attachChild(std::move(square));

    //std::unique_ptr<Enemy> enemy(new Enemy(mSpawnPosition.x + 10, mSpawnPosition.y + 10));
    //enemy->setPosition(Vector2f(mSpawnPosition.x + 10, mSpawnPosition.y + 10));
    //mSceneLayers[Background]->attachChild(std::move(enemy));
}