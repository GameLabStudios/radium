#include "GameWorld.hpp"
#include "Square.hpp"
#include "Enemy.hpp"

GameWorld* GameWorld::sGameWorld = nullptr;

GameWorld::GameWorld(RenderWindow& window) : World(window)
{
    loadTextures();
    buildScene();
}

GameWorld* GameWorld::getInstance()
{
    return sGameWorld;
}

GameWorld* GameWorld::createInstance(RenderWindow& window)
{
    if (sGameWorld == nullptr)
    {
        sGameWorld = new GameWorld(window);
    }

    return sGameWorld;
}

void GameWorld::update(Time dt)
{
    World::update(dt);

    // Camera tracks player
    mWorldView.setCenter(mPlayer->getPosition());
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
    std::unique_ptr<Square> square2(new Square());
    mPlayer->attachChild(std::move(square2));

    // Add Square to scene
    std::unique_ptr<Square> square(new Square());
    square->setPosition(mSpawnPosition);
    mSceneLayers[Foreground]->attachChild(std::move(square));

    std::unique_ptr<Enemy> enemy(new Enemy());
    enemy->setPosition(Vector2f(mSpawnPosition.x + 10, mSpawnPosition.y + 10));
    mSceneLayers[Background]->attachChild(std::move(enemy));
}

Player* GameWorld::getPlayer() const
{
    return mPlayer;
}