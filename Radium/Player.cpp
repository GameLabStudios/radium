#include <iostream>
#include <string>
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include "CircleRigidbody.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

Player::Player(Vector2f position)
{
	health = 100.0f;

    // SFML circle object
    circle = CircleShape(20, 30);
    circle.setOrigin(20.0f, 20.0f);
    circle.setFillColor(Color::Red);

    line = RectangleShape(Vector2f(20.0f, 5.0f));
    line.setOrigin(10.0f, 2.5f);
    line.setPosition(line.getPosition() + Vector2f(10.0f, 0.0));

    // player speed
	playerSpeed = 10.0f;

    // Ability variables
    abilityEquipped = 1;
    abilities[0] = addComponent<TeleportAbility>();
    abilities[1] = addComponent<ShieldAbility>();

    // Set Position
    setPosition(position);

    CircleRigidbody* rigidbody = addComponent<CircleRigidbody>();
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);
}

void Player::onDraw(RenderTarget& target, RenderStates states) const
{
	target.draw(circle, states);
    target.draw(line, states);
}

void Player::onFixedUpdate(Time dt)
{
    b2Vec2 position = rigidbody->body->GetPosition();
    
    // move player
    b2Vec2 pushDirection = b2Vec2(direction.x * playerSpeed, direction.y * -1.f * playerSpeed);
    if (pushDirection == b2Vec2_zero)
    {
        rigidbody->body->SetLinearVelocity(b2Vec2_zero);
    }
    else
    {
        rigidbody->body->SetLinearVelocity(pushDirection);
    }
    
    // debug movement push
    //std::cout << " push X: " << pushDirection.x << " push Y: " << pushDirection.y << std::endl;
}

void Player::onUpdate(Time dt)
{
	Vector2f mousePos = GameWorld::getInstance()->getMousePosition();

	float angle = atan2(mousePos.y - getPosition().y, mousePos.x - getPosition().x);
	setRotation((float)((angle * 180.0f) / M_PI));

	//direction of movement
	direction = Vector2f(0.0f, 0.0f);

	//input
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		direction.x -= 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		direction.x += 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		direction.y += 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		direction.y -= 1.0f;
	}

    if (Mouse::isButtonPressed(Mouse::Right))
    {
        switch (abilityEquipped)
        {
        case 0:
            dynamic_cast<TeleportAbility*>(abilities[abilityEquipped])->useAbility(rigidbody->body, angle);
            break;
        case 1:
            dynamic_cast<ShieldAbility*>(abilities[abilityEquipped])->useAbility(rigidbody->body, angle);
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

	//normalize the direction
	if (direction.x != 0.0f)
	{
		direction.x = direction.x / sqrt((direction.x*direction.x) + (direction.y*direction.y));
	}
	if (direction.y != 0.0f)
	{
		direction.y = direction.y / sqrt((direction.x*direction.x) + (direction.y*direction.y));
	}
	
	//move the player
	//move(direction * playerSpeed * dt.asSeconds());
}

void Player::handleEvent(const Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::A)
        {
        }
    }
    else if (event.type == Event::KeyReleased)
    {
        if (event.key.code == Keyboard::A)
        {
        }
        else if (event.key.code == Keyboard::Num1)
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