#pragma once

enum BT_Status { BT_INVALID, BT_SUCCESS, BT_FAILURE, BT_RUNNING};

/*
 * Base class for actions, conditions, and composites.
 */
class Behavior
{
public:
	Behavior() : m_status(BT_INVALID){}
	BT_Status tick();
	virtual BT_Status run() = 0;
	virtual void initialize() {}
	virtual void terminate(BT_Status) {}

private:
	BT_Status m_status;
};