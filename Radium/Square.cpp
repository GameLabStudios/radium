#include "Square.hpp"
#include <iostream>

Square::Square()
{
    square = RectangleShape(Vector2f(20.f, 20.f));
}

void Square::drawCurrent(RenderTarget& target, RenderStates states) const
{
    target.draw(square, states);
}

void Square::updateCurrent(Time dt)
{
    std::cout << "Square updated..\n";
}