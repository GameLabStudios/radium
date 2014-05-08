#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Ability.hpp"
#include "TeleportAbility.hpp"
#include "ShieldAbility.hpp"
using namespace sf;

class Player : public Entity
{
public:
	Player(Vector2f position);
    void            handleEvent(const sf::Event& event);
    void            takeDamage(float damage);
    void            heal(float health);

public:
    bool            isShooting; //Guerra authored for enemy testing

private:
	virtual void    onDraw(RenderTarget& target, RenderStates states) const;	
	virtual void    onUpdate(Time dt);
    virtual void    onFixedUpdate(Time dt);
    void            changeAbility(int num);

private:
	CircleShape     circle;
    RectangleShape  line;
    float           health;
	float           playerSpeed;
    Ability*        abilities[3];
    int             abilityEquipped;
    Vector2f        direction;
};