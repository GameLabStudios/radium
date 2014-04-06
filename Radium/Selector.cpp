#include "Selector.hpp"

void Selector::initialize()
{
	m_currentChild = m_children.begin();
}

BT_Status Selector::run()
{
	// Iterate through all of the children nodes.
	while (true)
	{
		BT_Status status = (*m_currentChild)->tick();

		// If child succeeds, or keeps running, quit out of the selector,
		// with the same status as the child.
		if (status != BT_FAILURE)
		{
			return status;
		}

		// If we hit the end of the children, then we quit out of
		// the selector with a status of failure.
		if (++m_currentChild == m_children.end())
		{
			status = BT_FAILURE;
		}
	}
	return BT_INVALID;
}