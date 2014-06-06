#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "BehaviorTree.hpp"
#include "Rigidbody.hpp"
#include "Player.hpp"

using namespace sf;
using namespace AI;

class Enemy : public Entity
{
// Functions
public:
    Enemy(Vector2f position);

    // Getters
    inline virtual float            getHealth() const;                // returns the health
    inline virtual int              getDamage() const;                // returns the amount of damage this enemy deals
    inline virtual Vector2f         getVelocity() const;              // returns the velocity
    inline virtual Color            getColor() const;                 // returns the color
    inline virtual BehaviorTree*    getBTree() const;                 // returns the root node of the behavior tree

    // Collision Handilng
    virtual void                    onBeginContact(b2Fixture* other, b2Contact* contact);
    virtual void                    onEndContact(b2Fixture* other, b2Contact* contact);

    // Miscellanseous
    virtual void                    takeDamage(float damage);         // updates health

protected:
    virtual void                    buildBehaviorTree() = 0;          // builds the behavior tree

    // Setters
    virtual void                    setHealth(float health);          // sets the health
    virtual void                    setDamage(int numSides);          // sets the amount of damage
    virtual void                    setVelocity(Vector2f velocity);   // sets the velocity
    virtual void                    setColor(Color color);            // sets the color
    virtual void                    setBTree(BehaviorTree* bTree);    // sets the behavior tree

private:
    virtual void                    onDraw(RenderTarget& target, RenderStates states) const;
    virtual void                    onUpdate(Time dt);
    //virtual void                    onFixedUpdate(Time dt);

// Variables
protected:
    float                           mHealth;                           // represents size
    int                             mDamage;                           // represents amount of damage
    Vector2f                        mVelocity;                         // the velocity of the enemy
    Color                           mColor;                            // the color of the enemy
    BehaviorTree*                   mBTree;                            // the behavior tree of the enemy
    float                           mBTreeFrequency;                   // how many seconds until the next update in the behavior tree

    // temporary so Guerra can write behaviors
    RectangleShape                  mRectShape;                        // the shape of the enemy
    RectangleShape                  mLine;

private:
    Player*                         mPlayer;
};

