#include "TestComponent.hpp"
#include <iostream>

TestComponent::TestComponent()
{

}

void TestComponent::onDestroy()
{
    std::cout << "Test Component onDestroy Called!\n";
}