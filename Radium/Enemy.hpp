#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "BehaviorTree.hpp"

using namespace sf;
using namespace AI;

class Enemy : public Entity
{
// Functions
public:
    Enemy();

    // Getters
    inline virtual float            getHealth() const;                // returns the health
    inline virtual int              getNumSides() const;              // returns the number
    inline virtual Vector2f         getVelocity() const;              // returns the velocity
    //inline virtual Vector2f         getPosition() const;              // returns the position
    inline virtual Color            getColor() const;                 // returns the color
    inline virtual float            getAlpha() const;                 // returns the alpha transparency
    inline virtual BehaviorTree*    getBTreeRoot() const;             // returns the root node of the behavior tree

protected:
    //virtual void                    buildBehaviorTree();              // builds the behavior tree from behavior nodes

    // Setters
    virtual void                    setHealth(float health);          // sets the health
    virtual void                    setNumSides(int numSides);        // sets the number of sides
    virtual void                    setVelocity(Vector2f velocity);   // sets the velocity
    //virtual void                    setPosition(Vector2f position);   // sets the position
    virtual void                    setColor(Color color);            // sets the color
    virtual void                    setAlpha(float alpha);            // sets the alpha transparency
    virtual void                    setBTreeRoot(BehaviorTree* bTree);// sets the root node of the behavior tree

private:
    virtual void                    onDraw(RenderTarget& target, RenderStates states) const;
    virtual void                    onUpdate(Time dt);

// Variables
protected:
    float                           health;                           // represents size
    int                             numSides;                         // represents amount of damage
    Vector2f                        velocity;                         // the velocity of the enemy
    //Vector2f                        position;                         // the position of the enemy
    Color                           color;                            // the color of the enemy
    float                           alpha;                            // the transparency of the enemy
    BehaviorTree*                   bTree;                            // the behavior tree of the enemy
};

