#pragma once

// Interface includes:
#include "IScript.h"
#include "IScriptRequestData.h"

#include "CIdleTask.h"

class KESSDIdleTask : public CIdleTask
{
public:

	KESSDIdleTask(IPMUnknown* boss);

	virtual uint32 RunTask(uint32 appFlags, IdleTimer* timeCheck);

	static bool16 flg;
};