#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Ability.hpp"
#include "Teleport.hpp"
using namespace sf;

class Player : public Entity
{
public:
	Player();
    void            handleEvent(const sf::Event& event);
    void            takeDamage(float damage);
    void            heal(float health);
    void            changeAbility();

public:
    bool            isShooting; //Guerra authored for enemy testing

private:
	virtual void    drawCurrent(RenderTarget& target, RenderStates states) const;	
	virtual void    updateCurrent(Time dt);

private:
	CircleShape     circle;
    float           health;
	float           playerSpeed;
    Ability         *abilities[3];
    int             abilityEquipped;
};