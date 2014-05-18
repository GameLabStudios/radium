#pragma once
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "SceneNode.hpp"

class Component;
class Rigidbody;

class Entity : public SceneNode
{
public: 
                            Entity();

    void                    destroy();

    template<typename T>
    T*                      addComponent();

    template<typename T>
    T*                      getComponent();

    template<typename T>
    std::vector<T*>         getComponents();

    void                    receiveBeginContact(b2Fixture* other, b2Contact* contact);
    void                    receiveEndContact(b2Fixture* other, b2Contact* contact);

public:
    // Helpful pointers to components
    Rigidbody*              rigidbody;

private:
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            updateCurrent(sf::Time dt);
    virtual void            fixedUpdateCurrent(sf::Time dt);
    virtual void            handleDestructionCurrent();

    virtual void            onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            onUpdate(sf::Time dt);
    virtual void            onFixedUpdate(sf::Time dt);
    virtual void            onDestroy();
    virtual void            onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void            onEndContact(b2Fixture* other, b2Contact* contact);

private:
    bool                    mDestuctionFlag;
    std::vector<Component*> components;
};

#include "Entity.inl"