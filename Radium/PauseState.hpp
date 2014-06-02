#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "World.hpp"

using namespace sf;

class PauseState : public State
{
public:
                    PauseState(StateStack& stack, Context context);
    virtual void    draw();
    virtual bool    update(Time dt);
    virtual bool    fixedUpdate(Time dt);
    virtual bool    handleEvent(const Event& event);

private:
    Text            pauseText;
    Rect<float>     textBox;
    RectangleShape*  rect;
};