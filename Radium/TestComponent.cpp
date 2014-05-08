#include "TestComponent.hpp"
#include <iostream>

TestComponent::TestComponent(Entity* entity) : Component(entity)
{

}

void TestComponent::onDestroy()
{
    std::cout << "Test Component onDestroy Called!\n";
}