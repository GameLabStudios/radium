#include "Gun.hpp"

Gun::Gun(Entity* entity) : Component(entity)
{
    mFiring = false;
    
    // Create All Bullets

}

void Gun::onUpdate(sf::Time dt)
{
    handleInput();

    if (mFiring)
    {

    }
}

void Gun::handleInput()
{
    // Check for left mouse click
    if (Mouse::isButtonPressed(Mouse::Button::Left))
    {
        if (!mFiring)
        {
            mFiring = true;
            std::cout << "Now Firing!\n";
        }
    }
    else
    {
        if (mFiring)
        {
            mFiring = false;
            std::cout << "Done Firing!\n";
        }
    }
}