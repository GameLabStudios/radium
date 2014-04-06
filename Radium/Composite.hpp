#pragma once
#include <vector>
#include "Behavior.hpp"

class Composite : public Behavior
{
public:
	void addChild(Behavior*);
protected:
	typedef std::vector<Behavior*> Behaviors;
	Behaviors m_children;
};