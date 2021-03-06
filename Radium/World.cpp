#include "World.hpp"
#include "Square.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>
#include <cmath>

World::World(RenderWindow& window) : mWindow(window),
mWorldView(window.getDefaultView()),
mWorldBounds(0.f, 0.f, mWorldView.getSize().x * 2, mWorldView.getSize().y * 2),
mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldView.getSize().y / 2.f)
{
    loadTextures();
    buildScene();

    // Prepare the view
    mWorldView.setCenter(mSpawnPosition);
}

void World::update(Time dt)
{
    // Update the scene graph heirarchy
    mSceneGraph.update(dt);
    // Check for destruction flags after update completes
    mSceneGraph.handleDestruction();
}

void World::fixedUpdate(Time dt)
{
    mSceneGraph.fixedUpdate(dt);
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
