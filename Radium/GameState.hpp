#pragma once
#include "State.hpp"
#include "World.hpp"
using namespace sf;

class GameState : public State
{
public:
                    GameState(StateStack& stack, Context context);
    virtual void    draw();
    virtual bool    update(Time dt);
    virtual bool    handleEvent(const Event& event);

private:
    World           mWorld;
};