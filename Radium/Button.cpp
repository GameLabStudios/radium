#include "Button.hpp"
#include "Game.hpp"

Button::Button()
{
    // default constructor
}

Button::Button(Vector2f position, Vector2f size, std::string title)
{
    defaultColor = Color(180, 180, 180, 180);
    selectedColor = Color(0, 0, 0, 255);
    hoverColor = Color(50, 50, 50, 180);

    mButtonBox = new RectangleShape(size);
    mButtonBox->setPosition(position);
    mButtonBox->setFillColor(defaultColor);

    mButtonBounding = Rect<float>(position, size);

    mButtonText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    mButtonText.setString(title);
    mButtonText.setPosition(position + Vector2f(20.0f, mButtonBox->getSize().y/6));

    selected = false;
    hover = false;
}

void Button::draw(RenderWindow* window)
{
    window->draw(*mButtonBox);
    window->draw(mButtonText);
}

void Button::update(Time dt, RenderWindow* window)
{
    
    Vector2i mouse = Mouse::getPosition(*(window));
    Vector2f mousePos = window->mapPixelToCoords(mouse);

    if (mButtonBounding.contains(mousePos))
    {
        hover = true;
        if (!selected)
        {
            mButtonBox->setFillColor(hoverColor);
        }
    }
    else
    {
        hover = false;
        if (!selected)
        {
            mButtonBox->setFillColor(defaultColor);
        }
    }
}

void Button::update(Time dt, RenderWindow* window, View view)
{

    Vector2i mouse = Mouse::getPosition(*(window));
    Vector2f mousePos = window->mapPixelToCoords(mouse, view);

    if (mButtonBounding.contains(mousePos))
    {
        hover = true;
        if (!selected)
        {
            mButtonBox->setFillColor(hoverColor);
        }
    }
    else
    {
        hover = false;
        if (!selected)
        {
            mButtonBox->setFillColor(defaultColor);
        }
    }
}

void Button::fixedUpdate(Time dt) 
{

}

void Button::setColor(Color color)
{
    mButtonBox->setFillColor(color);
    defaultColor = color;
}

void Button::setHoverColor(Color color)
{
    hoverColor = color;
}

void Button::setSelectColor(Color color)
{
    selectedColor = color;
}

void Button::setSize(Vector2f size)
{
    mButtonBox->setSize(size);
}

void Button::setPosition(Vector2f position)
{
    mButtonBox->setPosition(position);
    mButtonText.setPosition(position + Vector2f(20.0f, 20.0f));
}

void Button::setString(std::string title)
{
    mButtonText.setString(title);
}

void Button::move(const Vector2f moveDirection)
{
    mButtonBox->move(moveDirection);
    mButtonText.move(moveDirection);
    mButtonBounding.left = mButtonBox->getPosition().x;
    mButtonBounding.top = mButtonBox->getPosition().y;
}

void Button::gotSelected()
{
    selected = true;
    mButtonBox->setFillColor(selectedColor);
}

void Button::gotDeSelected()
{
    selected = false;
    mButtonBox->setFillColor(defaultColor);
}

void Button::addData(gun gunData)
{
    mData = gunData;
}

const Vector2f Button::getSize() const
{
    return mButtonBox->getSize();
}

const Vector2f Button::getPosition() const
{
    return mButtonBox->getPosition();
}

const std::string Button::getString() const
{
    return mButtonText.getString().toAnsiString();
}

const gun Button::getData() const
{
    return mData;
}

const bool Button::isSelected() const
{
    return selected;
}

const bool Button::isHover() const
{
    return hover;
}


