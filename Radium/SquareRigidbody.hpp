#include "Rigidbody.hpp"

class SquareRigidbody : public Rigidbody
{
public:
            SquareRigidbody(Entity* entity);
    void    setShape(RectangleShape shape);
};