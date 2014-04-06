#pragma once
#include "Composite.hpp"

class Sequence : public Composite
{
protected:
	Behaviors::iterator m_currentChild;

protected:

	virtual void initialize();

	virtual BT_Status run();
};