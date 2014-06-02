#pragma once
#include <string>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Component
{
public:
                        Component(Entity* entity);
    virtual             ~Component();
    void                destroy();

    // Events
    virtual void        onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void        onUpdate(sf::Time dt);
    virtual void        onFixedUpdate(sf::Time dt);
    virtual void        onDestroy();
    virtual void        onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void        onEndContact(b2Fixture* other, b2Contact* contact);

    //static bool         getUniqueFlag();
    bool                getDestructionFlag() const;

protected:
    //static bool         mUniqueFlag;
    Entity*             mEntity;
    bool                mDestructionFlag;
};