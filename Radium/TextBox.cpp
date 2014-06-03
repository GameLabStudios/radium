#include "TextBox.hpp"
#include "Game.hpp"

TextBox::TextBox()
{
	// default constructor
}

TextBox::TextBox(Vector2f position, Vector2f size, std::string title)
{
	Color defaultColor = Color(126, 126, 126, 220);

	mainBox = new RectangleShape(size);
	mainBox->setPosition(position);
	mainBox->setFillColor(defaultColor);

	mainText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
	mainText.setString(title);
	float stringLength = title.length() * 30;
	std::cout << "length : " << stringLength << std::endl;
	Vector2f stringPos = Vector2f(position.x + (size.x / 2) - stringLength/4, position.y - 40.0f);
	mainText.setPosition(stringPos);
}

void TextBox::draw(RenderWindow* window)
{
	window->draw(*mainBox);
	window->draw(mainText);
}