#pragma once
#include <Box2D/Box2D.h>
#include <queue>
#include "World.hpp"

class GameWorld : public World
{
public:
    virtual void                            update(Time dt);
    virtual void                            draw();
    virtual void                            fixedUpdate(Time dt);

    static GameWorld*                       getInstance();
    static GameWorld*                       createInstance(RenderWindow& window);

    Player*                                 getPlayer() const;
    b2World*                                getb2World();
    void                                    toggleDebugDraw();

    SceneNode*                              attachChildToNode(SceneNode* node, SceneNode::Ptr child);
    void                                    detachChildFromNode(SceneNode* node, SceneNode* child);

private:
                                            GameWorld(RenderWindow& window);
    void                                    buildScene();

private:
    static GameWorld*                       sGameWorld;
    Player*                                 mPlayer;
    MeleeEnemy*                             mMeleeEnemy;
    DodgingEnemy*                           mDodgingEnemy;
    b2World*                                mb2World;
    bool                                    mDrawDebug;
    std::queue<SceneNode::Ptr>              mAddChildQueue;
    std::queue<SceneNode*>                  mAddParentQueue;
    std::queue<SceneNode*>                  mRemoveChildQueue;
    std::queue<SceneNode*>                  mRemoveParentQueue;
};