#include <iostream>
#include "PauseState.hpp"
#include "Game.hpp"

PauseState::PauseState(StateStack& stack, Context context) : State(stack, context)
{
    rect = new RectangleShape(Vector2f(200.0f, 50.0f));
    rect->setPosition((getContext().window->getSize().x / 2) - (rect->getSize().x/2), 150);

    pauseText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    pauseText.setString("Paused");
    pauseText.setPosition((getContext().window->getSize().x / 2) - (rect->getSize().x/4.5f), 150.0f);
    pauseText.setColor(Color::Black);
}

void PauseState::draw()
{
    getContext().window->setView(getContext().window->getDefaultView());\
    getContext().window->draw(*rect);
    getContext().window->draw(pauseText);
}

bool PauseState::update(Time dt)
{
    return false;
}

bool PauseState::fixedUpdate(Time dt)
{
    return false;
}

bool PauseState::handleEvent(const Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::P)
        {
            requestStackPop();
        }
    }
    return false;
}