#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"
#include "Player.hpp"
using namespace sf;

class World : private NonCopyable
{
public:
	explicit World(RenderWindow& window);
	void update(Time dT);
	void draw();
	RenderWindow& getWindow() const;
	const Vector2f getMousePosition() const;

private:
	void buildScene();

private:
	enum Layer
	{
		Background,
		Foreground,
		LayerCount
	};

private:
	RenderWindow& mWindow;
	View mWorldView;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	FloatRect mWorldBounds;
	Vector2f mSpawnPosition;
	Player* mPlayer;
};