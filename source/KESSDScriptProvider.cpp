//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IIdleTask.h"
#include "IIdleTaskMgr.h"
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CScriptProvider.h"

// Project includes:
#include "KESSDScriptingDefs.h"
#include "KESSDID.h"
#include "KESSDIdleTask.h"

class KESSDScriptProvider : public CScriptProvider
{
public:

	KESSDScriptProvider(IPMUnknown* boss) : CScriptProvider(boss) {};

	virtual ErrorCode HandleMethod(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript);

private:

	ErrorCode GetSetSuppressDialogs(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript);
};

CREATE_PMINTERFACE(KESSDScriptProvider, kKESSDScriptProviderImpl)

ErrorCode KESSDScriptProvider::HandleMethod(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode result = kFailure;

	switch (scriptID.Get())
	{
	case e_KESSDSuppressDialogsIdleTask:
		result = this->GetSetSuppressDialogs(scriptID, iScriptRequestData, iScript);
		break;

	default:
		return CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript);
	}

	return result;
}

ErrorCode KESSDScriptProvider::GetSetSuppressDialogs(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript)
{
	ErrorCode status = kFailure;

	do
	{
		// ---------------------------------------------------------------------------------------
		// Query argument.
		ScriptData scriptData;
		bool16 bool16_flg;
		if (iScriptRequestData->ExtractRequestData(p_KESSDSuppressDialogsFlg, scriptData) == kFailure) break;

		if (scriptData.GetBoolean(&bool16_flg) == kFailure) break;

		// Set flg.
		KESSDIdleTask::flg = bool16_flg;

		// ---------------------------------------------------------------------------------------
		// Add task.
		InterfacePtr<IIdleTask> iIdleTask(::GetExecutionContextSession(), IID_IKESSDIDLETASK);
		if (iIdleTask == nil) break;

		InterfacePtr<IIdleTaskMgr> idleTaskMgr(::GetExecutionContextSession(), ::UseDefaultIID());
		if (idleTaskMgr == nil) break;

		idleTaskMgr->RemoveTask(iIdleTask); // RemoveTask
		idleTaskMgr->AddTask(iIdleTask, 0); // AddTask

		status = kSuccess;

	} while (false);

	return status;
}
