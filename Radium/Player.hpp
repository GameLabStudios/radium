#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.hpp"
#include "Ability.hpp"
#include "TeleportAbility.hpp"
#include "ShieldAbility.hpp"
#include "Inventory.hpp"

using namespace sf;

class Player : public Entity
{
public:
	Player(Vector2f position);
    void            handleEvent(const sf::Event& event);
    void            takeDamage(float damage);
    void            heal(float health);
    bool            getIsShooting();

    const Inventory getInventory() const;
    void            equipGun(gun gunData);
    const gun       getEquippedGun1() const;


private:
	virtual void    onDraw(RenderTarget& target, RenderStates states) const;	
	virtual void    onUpdate(Time dt);
    virtual void    onFixedUpdate(Time dt);
    virtual void    onBeginContact(b2Fixture* other, b2Contact* contact);
    void            changeAbility(int num);

private:
    CircleShape     circle;
    RectangleShape  line;
    float           health;
	float           playerSpeed;
    Ability*        abilities[3];
    int             abilityEquipped;
    Vector2f        direction;
    bool            isShooting;
    Text            text;

    Inventory       mInventory;
    int             mGunCounter;
    gun             mGun1;
};