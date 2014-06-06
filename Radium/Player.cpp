#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "GameWorld.hpp"
#include "Game.hpp"
#include "CircleRigidbody.hpp"
#include "PlayerMovement.hpp"
#include "Gun.hpp"
#include "TextComponent.hpp"
#include "CollisionFilters.hpp"

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
    rigidbody->setBits(Collision::PLAYER, ~Collision::PLAYER_BULLETS ^ Collision::SHIELD);
    rigidbody->createBody(Rigidbody::dynamicBody);
    rigidbody->setShape(circle);
    rigidbody->canRotate(false);

    // player movement component
    addComponent<PlayerMovement>();

    // Add Gun Component!
    addComponent<Gun>();
    TextComponent* textBox = addComponent<TextComponent>();
    textBox->setSize(Vector2f(40,40));
    textBox->setText("Player");
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
    rigidbody->body->SetTransform(rigidbody->body->GetPosition(), angle);

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

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        isShooting = true;
    }
    else
    {
        isShooting = false;
    }

    if (health <= 0)
    {
        destroy();
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
        if (event.key.code == Keyboard::P)
        {
            GameWorld::getInstance()->getState().requestStackPush(States::Pause);
        }
        if (event.key.code == Keyboard::I)
        {
            GameWorld::getInstance()->getState().requestStackPush(States::Inventory);
        }
        if (event.key.code == Keyboard::R)
        {
            getComponent<Gun>()->randomizeGun();
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

void Player::takeDamage(float damage)
{
    health -= damage;
    std::cout << "health: " << health << std::endl;
}

bool Player::getIsShooting()
{
    return isShooting;
}