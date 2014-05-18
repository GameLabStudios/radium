#pragma once
#include "World.hpp"
#include <Box2D/Box2D.h>

class GameWorld : public World
{
public:
    virtual void                        update(Time dt);
    virtual void                        draw();
    virtual void                        fixedUpdate(Time dt);

    static GameWorld*                   getInstance();
    static GameWorld*                   createInstance(RenderWindow& window);

    Player*                             getPlayer() const;
    b2World*                            getb2World();
    void                                toggleDebugDraw();
    void                                addEntityToWorld(std::unique_ptr<Entity> entity);

private:
                                        GameWorld(RenderWindow& window);
    void                                buildScene();

private:
    static GameWorld*                   sGameWorld;
    Player*                             mPlayer;
    MeleeEnemy*                         mMeleeEnemy;
    b2World*                            mb2World;
    bool                                mDrawDebug;
};