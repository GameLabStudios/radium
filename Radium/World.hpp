#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "Player.hpp"
#include "MeleeEnemy.hpp"
#include "DodgingEnemy.hpp"
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
    virtual void                        update(Time dT);
    virtual void                        fixedUpdate(Time dt);
    virtual void                        draw();
    RenderWindow&                       getWindow() const;
    const Vector2f                      getMousePosition() const;

protected:
    virtual void                        loadTextures();
    virtual void                        buildScene();

protected:
    enum Layer
    {
        Background,
        Foreground,
        LayerCount
    };

protected:
    RenderWindow&                       mWindow;
    View                                mWorldView;
    TextureHolder                       mTextures;

    SceneNode                           mSceneGraph;
    std::array<SceneNode*, LayerCount>  mSceneLayers;

    FloatRect                           mWorldBounds;
    Vector2f                            mSpawnPosition;
};