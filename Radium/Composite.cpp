#include "Composite.hpp"

void Composite::addChild(Behavior* newChild)
{
	m_children.push_back(newChild);
}