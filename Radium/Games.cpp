#include "Game.hpp"

Game::Game() : mWindow(VideoMode(640, 480), "Radium")
{

}

void Game::run()
{
	Clock clock;
	while (mWindow.isOpen())
	{
		Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents()
{
	Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mWindow.close();
		}
	}
}

void Game::update(Time deltaTime)
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.display();
}