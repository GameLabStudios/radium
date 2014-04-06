#include "Game.hpp"
#include <string>
#include <assert.h>

const Time Game::TimePerFrame = seconds(1.f / 60.f);

Game::Game() : mWindow(VideoMode(640, 480), "Radium"), mWorld(mWindow)
{
	mStatisticsNumFrames = 0;
	mFont.loadFromFile("Content/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;
	while (mWindow.isOpen())
	{
		Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		updateStatistics(deltaTime);
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
	mWorld.update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(Time deltaTime)
{
	mStatisticsUpdateTime += deltaTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString("fps: " + std::to_string(mStatisticsNumFrames) + "\ndT: " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
		mStatisticsUpdateTime -= seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

const World& Game::getWorld() const
{
	return mWorld;
}