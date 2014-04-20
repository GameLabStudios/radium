#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "StateStack.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;

class Game : private NonCopyable
{
public:
    static Game&        getInstance();
    void                run();
    static const int    xResolution;
    static const int    yResolution;
    static const float  m2p;
    static const float  p2m;

private:
                        Game();
    void                processEvents();
    void                update(Time);
    void                fixedUpdate(Time dt);
    void                render();
    void                updateStatistics(Time dt);
    void                registerStates();

private:
    static const Time   TimePerFrame;
    RenderWindow        mWindow;
    TextureHolder       mTextures;
    FontHolder          mFonts;
    
    StateStack          mStateStack;

    Text                mStatisticsText;
    Time                mStatisticsUpdateTime;
    std::size_t         mStatisticsNumFrames;
};