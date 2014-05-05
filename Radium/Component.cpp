#include "Component.hpp"

Component::Component()
{
    mDestructionFlag = false;
}

void Component::destroy()
{
    mDestructionFlag = true;
}

void Component::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // This function is intentionally left blank
}

void Component::onUpdate(sf::Time dt)
{
    // This function is intentionally left blank
}

void Component::onFixedUpdate(sf::Time dt)
{
    // This function is intentionally left blank
}

void Component::onDestroy()
{
    // This function is intentionally left blank
}

//static bool Component::getUniqueFlag()
//{
//    return mUniqueFlag;
//}

bool Component::getDestructionFlag() const
{
    return mDestructionFlag;
}