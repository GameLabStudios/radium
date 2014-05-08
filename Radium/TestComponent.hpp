#pragma once
#include "Component.hpp"

class TestComponent : public Component
{
public:
                    TestComponent(Entity* entity);
    virtual void    onDestroy();
};