#include "GameWorld.hpp"
#include "Square.hpp"
#include <iostream>

GameWorld* GameWorld::sGameWorld = nullptr;

GameWorld::GameWorld(RenderWindow& window) : World(window)
{
    sGameWorld = this;
    mb2World = new b2World(b2Vec2(0.0f, 0.0f));

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
    // Call Base update(dt)
    World::update(dt);

    // Camera tracks player
    mWorldView.setCenter(mPlayer->getPosition());
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
    std::unique_ptr<Player> player(new Player());
    mPlayer = player.get();
    player->setPosition(mSpawnPosition);
    mSceneLayers[Background]->attachChild(std::move(player));

    // Add Square to scene on mouseTest
    //std::unique_ptr<Square> square2(new Square());
    //mPlayer->attachChild(std::move(square2));

    // Add Square to scene
    std::unique_ptr<Square> square(new Square(mSpawnPosition));
    mSceneLayers[Foreground]->attachChild(std::move(square));
}

Player* GameWorld::getPlayer() const
{
    return mPlayer;
}

b2World* GameWorld::getb2World()
{
    return mb2World;
}