#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(Time);
	void render();

	RenderWindow mWindow;
};