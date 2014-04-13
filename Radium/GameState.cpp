#include "GameState.hpp"

GameState::GameState(StateStack& stack, Context context) : State(stack, context), mWorld(*context.window)
{
}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(Time dt)
{
    mWorld.update(dt);

    //CommandQueue& commands = mWorld.getCommandQueue();
    //mPlayer.handleRealtimeInput(commands);

    return true;
}

bool GameState::handleEvent(const Event& event)
{
    // Game input handling
    //CommandQueue& commands = mWorld.getCommandQueue();
    //mPlayer.handleEvent(event, commands);

    // Escape Pressed, trigger the pause screen
    //if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    //    requestStackPush(States::Pause);

    return true;
}