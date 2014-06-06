#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextBox.hpp"
#include "Button.hpp"

using namespace sf;

class ScrollBox : public TextBox
{
public:

                        ScrollBox();
                        ScrollBox(Vector2f pos, Vector2f size, std::string title);

    virtual void        draw(RenderWindow* window);
    virtual void        update(Time dt, RenderWindow* window);
    virtual void        fixedUpdate(Time dt);
    virtual void        handleEvent(const Event& event, RenderWindow* window);

    void                createView(FloatRect viewSize, FloatRect viewPort);
    void                addItems(std::vector<Button> items);

    bool                hasSelected() const;
    Button              getSelected() const;

private:
    View*               mView;
    RectangleShape*     scrollWheel;
    std::vector<Button> mItems;

    int                 selectedItem;
    Vector2f            moveDirection;
    Vector2f            minMove;
    Vector2f            maxMove;
    Vector2f            currPos;
    float               scrollOffset;
};