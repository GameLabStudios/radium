#include "Game.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"
#include "InventoryState.hpp"
#include <string>

const Time Game::TimePerFrame = seconds(1.f / 60.0f);

const int Game::xResolution = 1280;
const int Game::yResolution = 720;
const float Game::m2p = 30.0f;
const float Game::p2m = 1.0f / 30.0f;

Game::Game() : mWindow(VideoMode(xResolution, yResolution), "Radium"),
mTextures(),
mFonts(),
mStateStack(State::Context(mWindow, mTextures, mFonts))
{
    mStatisticsNumFrames = 0;

    mFonts.load(Fonts::Main, "Content/Sansation.ttf");

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);
    
    registerStates();
    mStateStack.pushState(States::Game);

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
            fixedUpdate(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
            {
                mWindow.close();
            }
        }
        update(deltaTime);
        updateStatistics(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);
        if (event.type == Event::Closed)
        {
            mWindow.close();
        }
    }
}

void Game::update(Time dt)
{
    mStateStack.update(dt);
}

void Game::fixedUpdate(Time dt)
{
    mStateStack.fixedUpdate(dt);
}

void Game::render()
{
    mWindow.clear();
    mStateStack.draw();
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

void Game::registerStates()
{
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<InventoryState>(States::Inventory);
}

Game& Game::getInstance()
{
    static Game instance;
    return instance;
}

const TextureHolder& Game::getTextures() const
{
    return mTextures;
}

const FontHolder& Game::getFonts() const
{
    return mFonts;
}