#include "Behavior.hpp"

BT_Status Behavior::tick()
{
	if (m_status == BT_INVALID)
	{
		initialize();
	}

	m_status = run();

	if (m_status != BT_RUNNING)
	{
		terminate(m_status);
	}
	return m_status;
}