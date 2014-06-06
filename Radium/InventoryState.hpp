#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "World.hpp"
#include "TextBox.hpp"
#include "ScrollBox.hpp"
#include "Button.hpp"

using namespace sf;

class InventoryState : public State
{
public:
                                    InventoryState(StateStack& stack, Context context);
    virtual void                    draw();
    virtual bool                    update(Time dt);
    virtual bool                    fixedUpdate(Time dt);
    virtual bool                    handleEvent(const Event& event);

private:
    // variable for stat box
    TextBox							statsBox;
    Text*                           gunName;        // text for select gun name
    std::vector<Text>               gunStats;       // vector that holds all text for gun attributes
    int                             selectedItem;   // int of selected variable

    // variables for main inventory box
    ScrollBox						mainInvBox;
    RectangleShape*                 invScroll;
    Rect<float>                     scrollBoundBox;

    // variables for equipped box
    TextBox                         equip1Box;
    TextBox                         equip2Box;

    std::vector<Button>             inventoryList;  // vector of inventory objects

    std::vector<std::string>        tempList;       // temporary list
};