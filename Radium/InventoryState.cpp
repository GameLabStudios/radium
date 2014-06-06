#include <iostream>
#include <sstream>
#include "InventoryState.hpp"
#include "Game.hpp"
#include "GameWorld.hpp"

InventoryState::InventoryState(StateStack& stack, Context context) : State(stack, context)
{
    // get the player's inventory
    std::vector<gun> mInventory = GameWorld::getInstance()->getPlayer()->getInventory().getInv();
    gun currGun = GameWorld::getInstance()->getPlayer()->getEquippedGun1();

    // button positions
    Vector2f tmpPos = Vector2f(0.0f, 0.0f);

    // add all guns to inventory button list for display
    for (unsigned i = 0; i < mInventory.size(); i++)
    {
        Button addItem = Button(tmpPos, Vector2f(450, 80), mInventory[i].name);
        addItem.addData(mInventory[i]);
        inventoryList.push_back(addItem);
        tmpPos += Vector2f(0.0f, 100.0f);
    }

    // create statistic box for selected gun
	statsBox = TextBox(Vector2f(200.0f, 70.0f), Vector2f(500.0f, 300.0f), "Stats");

    // create empty stats text for statistic box
    createDefaultStatsText(&gunStats, Vector2f(220.0f, 110.0f), Vector2f(1.0f, 1.0f));

    // create equip to slot 1 button
    equipButton = Button(Vector2f(220.f, 290.f), Vector2f(190.f, 60.f), "Equip Slot 1");
    
    // create gun name text
	gunName = new Text();
    gunName->setFont(Game::getInstance().getFonts().get(Fonts::Main));
    gunName->setPosition(Vector2f(220.0f, 80.0f));
    gunName->setString("");

    // create slot 1 and slot 2 boxes
    equip1Box = TextBox(Vector2f(90.f, 420.f), Vector2f(320.f, 250.f), "Slot 1");
    equip2Box = TextBox(Vector2f(500.f, 420.f), Vector2f(320.f, 250.f), "Slot 2");

    // create slot 1 and slot 2 default stats text
    createDefaultStatsText(&equip1Stats, Vector2f(110.0f, 480.0f), Vector2f(0.5f, 0.5f));
    setStats(&equip1Stats, currGun);

    // create slot 1 name text
    equip1Name = new Text();
    equip1Name->setFont(Game::getInstance().getFonts().get(Fonts::Main));
    equip1Name->setPosition(Vector2f(110, 440.0f));
    equip1Name->setString(currGun.name);

    // create the inventory box, holding all the guns
	mainInvBox = ScrollBox(Vector2f(getContext().window->getSize().x / 2 + 200, 70.0f), Vector2f(400.0f, 600.0f), "Inventory");
    mainInvBox.createView(FloatRect(0, 0, 1280, 720), FloatRect(0.68f, 0.13f, 0.75f, 0.75f));
    if (inventoryList.size() > 0)
    {
        mainInvBox.addItems(inventoryList);
    }

    // set selectedItem variable to default
    selectedItem = false;

    // create exit button
    exitButton = Button(Vector2f(20, 20), Vector2f(100, 60), "Exit");
    exitButton.setColor(Color(255, 0, 0, 150));
    exitButton.setHoverColor(Color(170, 0, 0, 150));
    exitButton.setSelectColor(Color(80, 0, 0, 150));
}

void InventoryState::draw()
{
    getContext().window->setView(getContext().window->getDefaultView());

	statsBox.draw(getContext().window);
    getContext().window->draw(*gunName);
    drawStats(gunStats, getContext().window);

    equipButton.draw(getContext().window);

    equip1Box.draw(getContext().window);
    getContext().window->draw(*equip1Name);
    drawStats(equip1Stats, getContext().window);

    equip2Box.draw(getContext().window);
    exitButton.draw(getContext().window);

	mainInvBox.draw(getContext().window);
}

bool InventoryState::update(Time dt)
{
    mainInvBox.update(dt, getContext().window);
    equipButton.update(dt, getContext().window);
    exitButton.update(dt, getContext().window);
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

    if (event.type == Event::MouseButtonPressed)
    {
        if (equipButton.isHover() && selectedItem)
        {
            equipButton.gotSelected();
            gun gunData = mainInvBox.getSelected().getData();
            GameWorld::getInstance()->getPlayer()->equipGun(gunData);
            equip1Name->setString(gunData.name);
            setStats(&equip1Stats, gunData);
        }
        if (exitButton.isHover())
        {
            exitButton.gotSelected();
        }
    }

    if (event.type == Event::MouseButtonReleased)
    {
        if (mainInvBox.hasSelected())
        {
            gunName->setString(mainInvBox.getSelected().getString());
            gun gunData = mainInvBox.getSelected().getData();
            setStats(&gunStats, gunData);
            
            selectedItem = true;
        }
        equipButton.gotDeSelected();
        if (exitButton.isHover())
        {
            requestStackPop();
        }
    }
    return false;
}

void InventoryState::createDefaultStatsText(std::vector<Text>* group, Vector2f pos, Vector2f scale)
{
    Vector2f offSet = Vector2f(0.0f, 30.0f);
    Text damageText = Text();
    damageText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    damageText.setString("Damage           : ");
    damageText.setScale(scale);
    damageText.setPosition(pos + (offSet * 0.0f));

    Text spreadText = Text();
    spreadText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    spreadText.setString("Spread Angle : ");
    spreadText.setScale(scale);
    spreadText.setPosition(pos + (offSet * 1.0f));

    Text bulletText = Text();
    bulletText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    bulletText.setString("Bullet Speed   : ");
    bulletText.setScale(scale);
    bulletText.setPosition(pos + (offSet * 2.0f));

    Text armorText = Text();
    armorText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    armorText.setString("Armor Pen       : ");
    armorText.setScale(scale);
    armorText.setPosition(pos + (offSet * 3.0f));

    Text cooldownText = Text();
    cooldownText.setFont(Game::getInstance().getFonts().get(Fonts::Main));
    cooldownText.setString("Cooldown        : ");
    cooldownText.setScale(scale);
    cooldownText.setPosition(pos + (offSet * 4.0f));

    group->push_back(damageText);
    group->push_back(spreadText);
    group->push_back(bulletText);
    group->push_back(armorText);
    group->push_back(cooldownText);
}

void InventoryState::drawStats(std::vector<Text> group, RenderWindow* window)
{
    for (unsigned i = 0; i < group.size(); i++)
    {
        window->draw(group[i]);
    }
}

void InventoryState::setStats(std::vector<Text>* group, gun gunData)
{
    group->at(0).setString("Damage           : " + std::to_string(gunData.damage));
    group->at(1).setString("Spread Angle : " + std::to_string(gunData.spread));
    group->at(2).setString("Bullet Speed   : " + std::to_string(gunData.bulletSpeed));
    group->at(3).setString("Armor Pen       : " + std::to_string(gunData.armorPen));
    group->at(4).setString("Cooldown        : " + std::to_string(gunData.cooldown));
}
