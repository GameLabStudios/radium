#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include "CircleRigidbody.hpp"
#include "PlayerMovement.hpp"
#include "TestGun.hpp"

Player::Player(Vector2f position)
{
	health = 100.0f;

    // SFML circle object
    circle = CircleShape(20, 30);
    circle.setOrigin(20.0f, 20.0f);
    circle.setFillColor(Color::Green);

    line = RectangleShape(Vector2f(20.0f, 5.0f));
    line.setOrigin(10.0f, 2.5f);
    line.setPosition(line.getPosition() + Vector2f(10.0f, 0.0));

    // Set Position
    setPosition(position);

    // Ability components
    abilityEquipped = 1;
    abilities[0] = addComponent<TeleportAbility>();
    abilities[1] = addComponent<ShieldAbility>();

    // rigidbody component
    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);

    // player movement component
    addComponent<PlayerMovement>();

    // Add Gun Component!
    addComponent<TestGun>();
}

void Player::onDraw(RenderTarget& target, RenderStates states) const
{

	target.draw(circle, states);
    target.draw(line, states);
}

void Player::onFixedUpdate(Time dt)
{
}

void Player::onUpdate(Time dt)
{
	Vector2f mousePos = GameWorld::getInstance()->getMousePosition();

	float angle = atan2(mousePos.y - getPosition().y, mousePos.x - getPosition().x);
	setRotation((float)((angle * 180.0f) / M_PI));
	
    if (Mouse::isButtonPressed(Mouse::Right))
    {
        switch (abilityEquipped)
        {
        case 0:
            dynamic_cast<TeleportAbility*>(abilities[abilityEquipped])->useAbility(angle);
            break;
        case 1:
            dynamic_cast<ShieldAbility*>(abilities[abilityEquipped])->useAbility(angle);
            break;
        case 2:
            break;
        default:
            break;
        }
    }

    // Guerra authored for enemy testing...will take out eventually
    // TODO: Take this shit out.
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        isShooting = true;
        //std::cout << "shooting" << std::endl;
    }
    else
    {
        //std::cout << "not shooting" << std::endl;
        isShooting = false;
    }
}

void Player::handleEvent(const Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::O)
        {
            GameWorld::getInstance()->toggleDebugDraw();
        }
        if (event.key.code == Keyboard::A)
        {
        }
    }
    else if (event.type == Event::KeyReleased)
    {
        if (event.key.code == Keyboard::Num1)
        {
            changeAbility(0);
        }
        else if (event.key.code == Keyboard::Num2)
        {
            changeAbility(1);
        }
    }
}

void Player::changeAbility(int num)
{
    std::cout << "changed ability to " << num << std::endl;
    abilityEquipped = num;
}

void Player::onBeginContact(b2Fixture* other, b2Contact* contact)
{
}