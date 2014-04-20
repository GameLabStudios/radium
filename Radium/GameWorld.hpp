#pragma once
#include "World.hpp"
#include <Box2D/Box2D.h>

class GameWorld : public World
{
public:
    void                                update(Time dt);
    void                                fixedUpdate(Time dt);
    Player*                             getPlayer() const;
    b2World*                            getb2World();
    static GameWorld*                   getInstance();
    static GameWorld*                   createInstance(RenderWindow& window);

private:
    GameWorld(RenderWindow& window);
    static GameWorld*                   sGameWorld;
    void                                buildScene();
    Player*                             mPlayer;
    b2World*                            mb2World;
};