#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class TextBox
{
public:
			TextBox();
			TextBox(Vector2f position, Vector2f size, std::string title);
			
	void	setColor(Color color);
	void	draw(RenderWindow* window);

private:
	Vector2f		size;
	Vector2f		position;
	RectangleShape*	mainBox;
	Text			mainText;

};