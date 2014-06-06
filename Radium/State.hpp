#pragma once
#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
using namespace sf;

namespace sf
{
    class RenderWindow;
}

class StateStack;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(RenderWindow& window, TextureHolder& textures, FontHolder& fonts);
        RenderWindow*	    window;
        TextureHolder*		textures;
        FontHolder*			fonts;
    };


public:
    State(StateStack& stack, Context context);
    virtual				~State();

    virtual void		draw() = 0;
    virtual bool		update(Time dt) = 0;
    virtual bool        fixedUpdate(Time dt) = 0;
    virtual bool		handleEvent(const sf::Event& event) = 0;

    void				requestStackPush(States::ID stateID);
    void				requestStackPop();
    void				requestStateClear();


protected:
    Context				getContext() const;


private:
    StateStack*			mStack;
    Context				mContext;
};