#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"
using namespace sf;

class Entity : public SceneNode
{
public:
	void setVelocity(Vector2f velocity);
	void setVelocity(float vx, float vy);
	Vector2f getVelocity() const;

private:
	Vector2f mVelocity;
};