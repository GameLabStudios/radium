#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "GunProperties.hpp"

using namespace sf;

class Button
{
public:
                                Button();
                                Button(Vector2f position, Vector2f size, std::string title);

    virtual void                draw(RenderWindow* window);
    virtual void                update(Time dt, RenderWindow* window);
    virtual void                update(Time dt, RenderWindow* window, View view);
    virtual void                fixedUpdate(Time dt);

    void                        setColor(Color color);
    void                        setHoverColor(Color color);
    void                        setSelectColor(Color color);
    void                        setSize(Vector2f size);
    void                        setPosition(Vector2f position);
    void                        setString(std::string title);
    void                        move(const Vector2f moveDirection);
    void                        gotSelected();
    void                        gotDeSelected();
    void                        addData(gun gunData);

    const Vector2f              getSize() const;
    const Vector2f              getPosition() const;
    const std::string           getString() const;
    const gun                   getData() const;
    const bool                  isSelected() const;
    const bool                  isHover() const;

protected:

    RectangleShape*             mButtonBox;
    Text                        mButtonText;
    Rect<float>                 mButtonBounding;
    gun                         mData;

    Vector2f                    movePos;
    bool                        selected;
    bool                        hover;

    Color                       defaultColor;
    Color                       selectedColor;
    Color                       hoverColor;
};
