#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace sf;

class Player : public Entity
{
public:
	Player();

private:
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;	
	virtual void updateCurrent(Time dt);

private:
	CircleShape circle;
	float playerSpeed;
};