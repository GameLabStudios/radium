#include "Entity.hpp"
#include "Component.hpp"
#include <iostream>

Entity::Entity()
{
    mDestuctionFlag = false;
}

void Entity::destroy()
{
    mDestuctionFlag = true;
}

void Entity::receiveBeginContact(b2Fixture* other, b2Contact* contact)
{
    onBeginContact(other, contact);
    for (Component* component : components)
    {
        component->onBeginContact(other, contact);
    }
}

void Entity::receiveEndContact(b2Fixture* other, b2Contact* contact)
{
    onEndContact(other, contact);
    for (Component* component : components)
    {
        component->onEndContact(other, contact);
    }
}

void Entity::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Call draw on self then on components
    onDraw(target, states);
    for (Component* component : components)
    {
        component->onDraw(target, states);
    }
}

void Entity::updateCurrent(sf::Time dt)
{
    // Update self then update components
    onUpdate(dt);
    for (Component* component : components)
    {
        component->onUpdate(dt);
    }
}

void Entity::fixedUpdateCurrent(sf::Time dt)
{
    // Call fixed update on self then on components
    onFixedUpdate(dt);
    for (Component* component : components)
    {
        component->onFixedUpdate(dt);
    }
}

void Entity::handleDestructionCurrent()
{
    // If marked for destruction, mark all components for destruction
    if (mDestuctionFlag)
    {
        // Flag all children for destruction
        for (Component* component : components)
        {
            component->destroy();
        }

        // Call onDestroy event on self
        onDestroy();
    }

    // Check for components needing destruction
    for (std::vector<Component*>::iterator it = components.begin(); it != components.end();)
    {
        Component* component = *it;
        // Check if component is marked for destruction
        if (component->getDestructionFlag())
        {
            // Call onDestory event on component
            component->onDestroy();
            // Remove component from components list
            it = components.erase(it);
            // Delete component
            delete component;
        }
        // Advanced iterator, done this way to handle issue raised by using erase
        if (it != components.end())
        {
            ++it;
        }
    }
    
    // Destroy self
    if (mDestuctionFlag)
    {
        removeFromScene();
    }
}

void Entity::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // This function is intentionally left blank
}

void Entity::onDestroy()
{
    // This function is intentionally left blank
}

void Entity::onUpdate(sf::Time dt)
{
    // This function is intentionally left blank
}

void Entity::onFixedUpdate(sf::Time dt)
{
    // This function is intentionally left blank
}

void Entity::onBeginContact(b2Fixture* other, b2Contact* contact)
{
    // This function is intentionally left blank
}

void Entity::onEndContact(b2Fixture* other, b2Contact* contact)
{
    // This function is intentionally left blank
}