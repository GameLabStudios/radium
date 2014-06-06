#include <iostream>
#include <sstream>
#include "InventoryState.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

InventoryState::InventoryState(StateStack& stack, Context context) : State(stack, context)
{

    for (int i = 0; i < 20; i++)
    {
        std::ostringstream tmpText;
        tmpText << "Testing " << i;
        tempList.push_back(tmpText.str());
    }

    Vector2f tmpPosText = Vector2f(20.0f, 20.0f);
    Vector2f tmpPos = Vector2f(0.0f, 0.0f);

    for (String name : tempList)
    {

        Button addItem = Button(tmpPos, Vector2f(450, 80), name);
        inventoryList.push_back(addItem);
        tmpPos += Vector2f(0.0f, 100.0f);
    }

	statsBox = TextBox(Vector2f(200.0f, 70.0f), Vector2f(500.0f, 300.0f), "Stats");
    
	gunName = new Text();
    gunName->setFont(Game::getInstance().getFonts().get(Fonts::Main));
    gunName->setPosition(Vector2f(220.0f, 80.0f));
    gunName->setString("");

    equip1Box = TextBox(Vector2f(90.f, 420.f), Vector2f(320.f, 250.f), "Slot 1");
    equip2Box = TextBox(Vector2f(500.f, 420.f), Vector2f(320.f, 250.f), "Slot 2");


	mainInvBox = ScrollBox(Vector2f(getContext().window->getSize().x / 2 + 200, 70.0f), Vector2f(400.0f, 600.0f), "Inventory");
    mainInvBox.createView(FloatRect(0, 0, 1280, 720), FloatRect(0.68f, 0.13f, 0.75f, 0.75f));
    mainInvBox.addItems(inventoryList);

    selectedItem = -1;
}

void InventoryState::draw()
{
    getContext().window->setView(getContext().window->getDefaultView());

	statsBox.draw(getContext().window);
    getContext().window->draw(*gunName);

    equip1Box.draw(getContext().window);
    equip2Box.draw(getContext().window);

	mainInvBox.draw(getContext().window);
}

bool InventoryState::update(Time dt)
{
    mainInvBox.update(dt, getContext().window);
    return false;
}

bool InventoryState::fixedUpdate(Time dt)
{
    mainInvBox.fixedUpdate(dt);
    return false;
}

bool InventoryState::handleEvent(const Event& event)
{
    mainInvBox.handleEvent(event, getContext().window);
    
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::I)
        {
            requestStackPop();
        }
    }

    if (event.type == Event::MouseButtonReleased)
    {
        if (mainInvBox.hasSelected())
        {
            gunName->setString(mainInvBox.getSelected().getString());
        }
    }

    return false;
}

