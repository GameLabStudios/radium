#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

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
    void                        setSize(Vector2f size);
    void                        setPosition(Vector2f position);
    void                        setString(std::string title);
    void                        move(const Vector2f moveDirection);
    void                        gotSelected();
    void                        gotDeSelected();

    const Vector2f              getSize() const;
    const Vector2f              getPosition() const;
    const std::string           getString() const;
    const bool                  isSelected() const;
    const bool                  isHover() const;

protected:

    RectangleShape*             mButtonBox;
    Text                        mButtonText;
    Rect<float>                 mButtonBounding;
    Vector2f                    movePos;
    bool                        selected;
    bool                        hover;

    Color                       defaultColor;
    Color                       selectedColor;
    Color                       hoverColor;
};
