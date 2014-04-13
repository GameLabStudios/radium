#include "World.hpp"
#include "Square.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>
#include <cmath>

World::World(RenderWindow& window) : mWindow(window),
mWorldView(window.getDefaultView()),
mWorldBounds(0.f, 0.f, mWorldView.getSize().x * 2, mWorldView.getSize().y * 2),
mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
{
    loadTextures();
    buildScene();

    // Prepare the view
    mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
    mSceneGraph.update(dt);

    // Camera tracks player
    mWorldView.setCenter(mPlayer->getPosition());
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{

}

void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add player to scene
    std::unique_ptr<Player> mouseTest(new Player());
    mPlayer = mouseTest.get();
    mouseTest->setPosition(mSpawnPosition);
    mSceneLayers[Foreground]->attachChild(std::move(mouseTest));

    // Add Square to scene on mouseTest
    std::unique_ptr<Square> square2(new Square());
    mPlayer->attachChild(std::move(square2));

    // Add Square to scene
    std::unique_ptr<Square> square(new Square());
    square->setPosition(mSpawnPosition);
    mSceneLayers[Background]->attachChild(std::move(square));
}

RenderWindow& World::getWindow() const
{
    return mWindow;
}

const Vector2f World::getMousePosition() const
{
    Vector2i mouse = Mouse::getPosition(mWindow);
    return mWindow.mapPixelToCoords(mouse, mWorldView);
}

Player* World::getPlayer() const
{
    return mPlayer;
}