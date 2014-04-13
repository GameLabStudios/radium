#include "GameState.hpp"

GameState::GameState(StateStack& stack, Context context) : State(stack, context)
{
    mWorld = GameWorld::createInstance(*context.window);
}

void GameState::draw()
{
    mWorld->draw();
}

bool GameState::update(Time dt)
{
    mWorld->update(dt);
    return true;
}

bool GameState::handleEvent(const Event& event)
{
    mWorld->getPlayer()->handleEvent(event);
    return true;
}