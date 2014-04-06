#include "Sequence.hpp"

void Sequence::initialize()
{
	m_currentChild = m_children.begin();
}

BT_Status Sequence::run()
{
	// Iterate through all of the children nodes.
	while (true)
	{
		BT_Status status = (*m_currentChild)->tick();

		// If child fails, or keeps running, quit out of the sequence, 
		// with the same status as that child.
		if (status != BT_SUCCESS)
		{
			return status;
		}

		// If we hit the end of the children, then we can quit out of
		// the sequence with a status of success.
		if (++m_currentChild == m_children.end())
		{
			return BT_SUCCESS;
		}
	}
	return BT_INVALID;
}