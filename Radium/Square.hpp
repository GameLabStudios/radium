#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace sf;

class Square : public Entity
{
public:
	Square();

private:
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
	virtual void updateCurrent(Time dt);

private:
	RectangleShape square;
};