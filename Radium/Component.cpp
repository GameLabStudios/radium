#include "Component.hpp"

Component::Component(Entity* entity)
{
    mEntity = entity;
    mDestructionFlag = false;
}

Component::~Component()
{
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

void Component::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    // This function is intentionally left blank
}

void Component::onEndContact(b2Fixture* other, b2Contact* contact)
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