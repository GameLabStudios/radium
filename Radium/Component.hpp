#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Component
{
public:
                        Component(Entity* entity);

    void                destroy();

    // Events
    virtual void        onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void        onUpdate(sf::Time dt);
    virtual void        onFixedUpdate(sf::Time dt);
    virtual void        onDestroy();

    //static bool         getUniqueFlag();
    bool                getDestructionFlag() const;

protected:
    //static bool         mUniqueFlag;
    Entity*             mEntity;
    bool                mDestructionFlag;
};