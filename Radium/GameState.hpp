#pragma once
#include "State.hpp"
#include "GameWorld.hpp"
using namespace sf;

class GameState : public State
{
public:
                    GameState(StateStack& stack, Context context);
    virtual void    draw();
    virtual bool    update(Time dt);
    virtual bool    handleEvent(const Event& event);

private:
    GameWorld*      mWorld;
};