#pragma once
#include "World.hpp"

class GameWorld : public World
{
public:
    void                                update(Time dt);
    Player*                             getPlayer() const;
    static GameWorld*                   getInstance();
    static GameWorld*                   createInstance(RenderWindow& window);

private:
    GameWorld(RenderWindow& window);
    static GameWorld*                   sGameWorld;
    void                                buildScene();
    Player*                             mPlayer;
};