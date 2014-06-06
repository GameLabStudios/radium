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
	
    virtual void	    draw(RenderWindow* window);

    void	            setColor(Color color);

protected:
	Vector2f		    mSize;
	Vector2f		    mPosition;
	RectangleShape*	    mMainBox;
	Text			    mMainText;

};