#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Component
{
public:
                        Component();

    void                destroy();

    // Events
    virtual void        onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void        onUpdate(sf::Time dt);
    virtual void        onFixedUpdate(sf::Time dt);
    virtual void        onDestroy();

    //static bool         getUniqueFlag();
    bool                getDestructionFlag() const;

private:
    //static bool         mUniqueFlag;
    bool                mDestructionFlag;
};