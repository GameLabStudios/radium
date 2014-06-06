#include "ScrollBox.hpp"

ScrollBox::ScrollBox() : TextBox()
{
    // default constructor
}

ScrollBox::ScrollBox(Vector2f pos, Vector2f size, std::string title) : TextBox(pos, size, title)
{
    selectedItem = -1;
    currPos = Vector2f(0, 0);
}

void ScrollBox::draw(RenderWindow* window)
{
    TextBox::draw(window);
    window->setView(*mView);
    for (unsigned i = 0; i < mItems.size(); i++)
    {
        mItems[i].draw(window);
    }
}

void ScrollBox::update(Time dt, RenderWindow* window)
{
    for (unsigned i = 0; i < mItems.size(); i++)
    {
        mItems[i].update(dt, window, *mView);
    }
}

void ScrollBox::fixedUpdate(Time dt)
{
    for (unsigned i = 0; i < mItems.size(); i++)
    {
        if (maxMove.y >= (currPos.y + moveDirection.y) &&
            minMove.y <= (currPos.y + moveDirection.y))
        {
            mItems[i].move(moveDirection);
            currPos.y = mItems[mItems.size() - 1].getPosition().y - scrollOffset;
        }
        
    }
}

void ScrollBox::handleEvent(const Event& event, RenderWindow* window)
{

    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::S)
        {
            moveDirection = Vector2f(0.0f, -5.0f);
        }
        if (event.key.code == Keyboard::W)
        {
            moveDirection = Vector2f(0.0f, 5.0f);
        }
    }
    if (event.type == Event::KeyReleased)
    {
        moveDirection = Vector2f(0.0f, 0.0f);
    }

    if (event.type == Event::MouseButtonPressed)
    {
        Vector2i mouse = Mouse::getPosition(*window);
        Vector2f mousePos = window->mapPixelToCoords(mouse, *mView);
        for (unsigned i = 0; i < mItems.size(); i++)
        {
            if (mItems[i].isHover())
            {
                if (selectedItem != -1)
                {
                    mItems[selectedItem].gotDeSelected();
                }
                mItems[i].gotSelected();
                selectedItem = i;
            }
        }
    }
}


void ScrollBox::createView(FloatRect viewSize, FloatRect viewPort)
{
    mView = new View(viewSize);
    mView->setViewport(viewPort);
}

void ScrollBox::addItems(std::vector<Button> items)
{
    // set private variable of items
    mItems = items;

    // get the offset so last items stays at bottom
    scrollOffset = ((mView->getSize().y) * mView->getViewport().height) + items[0].getSize().y;
    
    // set min amd max and curr values for scroll
    minMove = items[0].getPosition();
    maxMove = items[items.size() - 1].getPosition();
    maxMove.y -= scrollOffset;
    currPos = maxMove;
}

bool ScrollBox::hasSelected() const
{
    if (selectedItem != -1)
    {
        return true;
    }
    return false;
}

Button ScrollBox::getSelected() const
{
    if (selectedItem != -1)
    {
        // return selected item if selected
        return mItems[selectedItem];
    }
}
