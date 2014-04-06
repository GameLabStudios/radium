#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "World.hpp"
using namespace sf;

class Game : private NonCopyable
{
public:
	static Game& getInstance();

	void run();
	const World& getWorld() const;

private:
	Game();
	void processEvents();
	void update(Time);
	void render();
	void updateStatistics(Time elapsedTime);

private:
	static const Time TimePerFrame;
	RenderWindow mWindow;
	World mWorld;

	Font mFont;
	Text mStatisticsText;
	Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
};