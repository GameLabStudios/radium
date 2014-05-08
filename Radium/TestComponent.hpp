#pragma once
#include "Component.hpp"

class TestComponent : public Component
{
public:
    TestComponent();
    virtual void onDestroy();
};