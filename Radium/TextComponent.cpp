#include <iostream>
#include "TextComponent.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

TextComponent::TextComponent(Entity* entity) : Component(entity)
{
    text.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    text.setString("placeholder");
    showText = false;
}

void TextComponent::setText(String txt)
{
    text.setString(txt);
}

void TextComponent::setSize(Vector2f size)
{
    Vector2f pos = mEntity->getPosition();
    textBox = Rect<float>(pos.x - size.x/2, pos.y - size.y/2, size.x, size.y);
}

void TextComponent::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    if (showText)
    {
        target.draw(text, states);
    }
}

void TextComponent::onUpdate(sf::Time dt)
{
    Vector2f mousePos = GameWorld::getInstance()->getMousePosition();
    if (textBox.contains(mousePos))
    {
        showText = true;
    }
    else  
    {
        showText = false;
    }
}

void TextComponent::onFixedUpdate(sf::Time dt)
{
    textBox.left = mEntity->getPosition().x - textBox.width / 2;
    textBox.top = mEntity->getPosition().y - textBox.height / 2;
}