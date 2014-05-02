#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Ability.hpp"
#include "Teleport.hpp"
using namespace sf;

class Player : public Entity
{
public:
	Player(Vector2f position);
    void            handleEvent(const sf::Event& event);
    void            takeDamage(float damage);
    void            heal(float health);
    void            changeAbility();

private:
	virtual void    drawCurrent(RenderTarget& target, RenderStates states) const;	
	virtual void    updateCurrent(Time dt);
    virtual void    fixedUpdateCurrent(Time dt);

private:
	CircleShape     circle;
    b2Body*         mBody;
    float           health;
	float           playerSpeed;
    Ability         *abilities[3];
    int             abilityEquipped;
    Vector2f        direction;
};