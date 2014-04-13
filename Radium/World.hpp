#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "MouseTest.hpp"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <queue>
using namespace sf;

// Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private NonCopyable
{
public:
    explicit                            World(RenderWindow& window);
    void                                update(Time dT);
    void                                draw();
    RenderWindow&                       getWindow() const;
    const Vector2f                      getMousePosition() const;

private:
    void                                loadTextures();
    void                                buildScene();

private:
    enum Layer
    {
        Background,
        Foreground,
        LayerCount
    };

private:
    RenderWindow&                       mWindow;
    View                                mWorldView;
    TextureHolder                       mTextures;

    SceneNode                           mSceneGraph;
    std::array<SceneNode*, LayerCount>  mSceneLayers;

    FloatRect                           mWorldBounds;
    Vector2f                            mSpawnPosition;
    MouseTest*                          mMouseTest;
};