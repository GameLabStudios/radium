#include <iostream>
#include <sstream>
#include "InventoryState.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

InventoryState::InventoryState(StateStack& stack, Context context) : State(stack, context)
{
    Color bgColor = Color(126, 126, 126, 220);

    statsBox = new RectangleShape(Vector2f(500.0f, 300.0f));
    statsBox->setPosition(Vector2f(200.0f, 70.0f));
    statsBox->setFillColor(bgColor);

    statsText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    statsText.setPosition(Vector2f(420, 30.0f));
    statsText.setString("Stats");

    gunName = new Text();
    gunName->setFont(Game::getInstance().getFonts().get(Fonts::Main));
    gunName->setPosition(Vector2f(220.0f, 80.0f));
    gunName->setString("");

    mainInvBox = new RectangleShape(Vector2f(400.0f, 600.0f));
    mainInvBox->setPosition(Vector2f(getContext().window->getSize().x / 2 + 200, 70.0f));
    mainInvBox->setFillColor(bgColor);

    mainInvText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    mainInvText.setPosition(Vector2f(getContext().window->getSize().x / 2 + 340, 30.0f));
    mainInvText.setString("Inventory");

    invScroll = new RectangleShape(Vector2f(10.0f, 30.0f));
    invScroll->setPosition(Vector2f(getContext().window->getSize().x / 2 + 580, 95.0f));

    invView = new View(FloatRect(0.0f, 0.0f, 1280.0f, 720.0f));
    invView->setViewport(FloatRect(0.68f, 0.13f, 0.75f, 0.75f));

    for (int i = 0; i < 20; i++)
    {
        std::ostringstream tmpText;
        tmpText << "Testing " << i;
        tempList.push_back(tmpText.str());
    }

    Vector2f tmpPosText = Vector2f(20.0f, 20.0f);
    Vector2f tmpPosBox = Vector2f(0.0f, 0.0f);

    for(String name : tempList)
    {
        Text addItem = Text();
        addItem.setFont(Game::getInstance().getFonts().get(Fonts::Main));
        addItem.setString(name);
        addItem.setPosition(tmpPosText);
        
        RectangleShape* box = new RectangleShape(Vector2f(450, 80));
        box->setPosition(tmpPosBox);
        box->setFillColor(Color(180, 180, 180, 180));

        Rect<float>* boundingBox = new Rect<float>(tmpPosBox, Vector2f(450, 80));

        tmpPosText += Vector2f(0.0f, 100.0f);
        tmpPosBox += Vector2f(0.0f, 100.0f);
        inventoryList.push_back(addItem);
        invBoxes.push_back(box);
        touchBoxes.push_back(boundingBox);
    }
}


void InventoryState::draw()
{
    getContext().window->setView(getContext().window->getDefaultView());

    getContext().window->draw(*statsBox);
    getContext().window->draw(statsText);
    getContext().window->draw(*gunName);

    getContext().window->draw(*mainInvBox);
    getContext().window->draw(*invScroll); 
    getContext().window->draw(mainInvText);
    

    

    getContext().window->setView(*invView);
    for (unsigned i = 0; i < inventoryList.size(); i++)
    {
        getContext().window->draw(*invBoxes[i]);
        getContext().window->draw(inventoryList[i]);
    }
}

bool InventoryState::update(Time dt)
{
    return false;
}

bool InventoryState::fixedUpdate(Time dt)
{
    for (unsigned i = 0; i < inventoryList.size(); i++)
    {
        if (invBoxes[0]->getPosition().y + direction.y <= 0.0f && 
            invBoxes[invBoxes.size() - 1]->getPosition().y + direction.y >= 640.0f)
        {
            inventoryList[i].move(direction);
            invBoxes[i]->move(direction);
            touchBoxes[i]->top += direction.y;
        }
    }
    return false;
}

bool InventoryState::handleEvent(const Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::I)
        {
            requestStackPop();
        }
        if (event.key.code == Keyboard::S)
        {
            direction = Vector2f(0.0f, -5.0f);
        }
        if (event.key.code == Keyboard::W)
        {
            direction = Vector2f(0.0f, 5.0f);
        }
    }
    if (event.type == Event::KeyReleased)
    {
        direction = Vector2f(0.0f, 0.0f);
    }

    if (event.type == Event::MouseButtonPressed)
    {
        Vector2i mouse = Mouse::getPosition(*(getContext().window));
        Vector2f mousePos = getContext().window->mapPixelToCoords(mouse, *invView);
        for (unsigned i = 0; i < touchBoxes.size(); i++)
        {
            if (touchBoxes[i]->contains(mousePos))
            {   
                if (gunName->getString().toAnsiString().compare("") != 0)
                {   
                    // if previous item was selected, change that
                    invBoxes[selectedItem]->setFillColor(Color(180, 180, 180, 180));
                }
                gunName->setString(inventoryList[i].getString().toAnsiString());
                
                // set the select color of item to black
                invBoxes[i]->setFillColor(Color::Black);
                selectedItem = i;
            }
        }
    }

    return false;
}

