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
    void                            createDefaultStatsText(std::vector<Text>* group, Vector2f pos, Vector2f scale);
    void                            drawStats(std::vector<Text> group, RenderWindow* window);
    void                            setStats(std::vector<Text>* group, gun gunData);

private:
    // variable for stat box
    TextBox							statsBox;
    Text*                           gunName;        // text for select gun name
    std::vector<Text>               gunStats;       // vector that holds all text for gun attributes
    bool                            selectedItem;   // int of selected variable
    Button                          equipButton;    // button to add selected gun to player

    // variables for main inventory box
    ScrollBox						mainInvBox;
    RectangleShape*                 invScroll;
    Rect<float>                     scrollBoundBox;

    // variables for equipped box
    TextBox                         equip1Box;
    Text*                           equip1Name;
    std::vector<Text>               equip1Stats;
    TextBox                         equip2Box;

    // exit inventory button
    Button                          exitButton;

    // vector of inventory objects, holds buttons that hold data of objects
    std::vector<Button>             inventoryList;  

};