#include "TextBox.hpp"
#include "Game.hpp"

TextBox::TextBox()
{
	// default constructor
}

TextBox::TextBox(Vector2f position, Vector2f size, std::string title)
{
	Color defaultColor = Color(126, 126, 126, 220);

    // create the box of the text box
	mMainBox = new RectangleShape(size);
    mMainBox->setPosition(position);
    mMainBox->setFillColor(defaultColor);

    // create the font of the text box
	mMainText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    mMainText.setString(title);
	float stringLength = title.length() * 30;

	//std::cout << "length : " << stringLength << std::endl;

    // set the string position according to the size of the text box and try to center it
	Vector2f stringPos = Vector2f(position.x + (size.x / 2) - stringLength/4, position.y - 40.0f);
    mMainText.setPosition(stringPos);
}

void TextBox::draw(RenderWindow* window)
{
    // draw the box and string
    window->draw(*mMainBox);
    window->draw(mMainText);
}