#include "Rigidbody.hpp"

class CircleRigidbody : public Rigidbody
{
public:
            CircleRigidbody(Entity* entity);
    void    setShape(CircleShape shape);
};