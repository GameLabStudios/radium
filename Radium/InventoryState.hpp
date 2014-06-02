#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "World.hpp"

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
    Text                            statsText;
    RectangleShape*                 statsBox;

    Text*                           gunName;        // text for select gun name
    std::vector<Text>               gunStats;       // vector that holds all text for gun attributes
    int                             selectedItem;   // int of selected variable

    // variables for main inventory box
    Text                            mainInvText;
    RectangleShape*                 mainInvBox;
    RectangleShape*                 invScroll;
    Rect<float>                     scrollBoundBox;

    View*                           invView;        // view of the scrolling inventory
    Vector2f                        direction;      // directional vector for moving inventory
    std::vector<Text>               inventoryList;  // vector of inventory objects
    std::vector<RectangleShape*>    invBoxes;       // display boxes behind the inventory
    std::vector<Rect<float>*>       touchBoxes;     // bounding boxes for inventory items

    std::vector<std::string>        tempList;       // temporary list
};