#pragma once
#include "CircleRigidbody.hpp"

class BulletRigidbody : public CircleRigidbody
{
public:
    BulletRigidbody(Entity* entity);
};