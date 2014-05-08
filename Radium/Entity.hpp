#pragma once
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <SFML/Graphics.hpp>
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

private:
    bool                    mDestuctionFlag;
    std::vector<Component*> components;
};

#include "Entity.inl"