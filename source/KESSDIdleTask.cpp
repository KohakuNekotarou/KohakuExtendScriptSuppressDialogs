//========================================================================================
//  
//  $File$
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author$
//  
//  $DateTime$
//  
//  $Revision$
//  
//  $Change$
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes.
#include "IApplication.h"
#include "IDialogMgr.h"

// General includes.
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CIdleTask.h"

// Project includes.
#include "KESSDID.h"
#include "KESSDIdleTask.h"

CREATE_PMINTERFACE(KESSDIdleTask, kKESSDIdleTaskImpl)

// static
bool16 KESSDIdleTask::flg = kFalse;

KESSDIdleTask::KESSDIdleTask(IPMUnknown *boss) : CIdleTask(boss) {}

uint32 KESSDIdleTask::RunTask(uint32 appFlags, IdleTimer* timeCheck)
{
	do
	{
		// ---------------------------------------------------------------------------------------
		// SetSuppressDialogs
		InterfacePtr<IApplication> iApplication(::GetExecutionContextSession()->QueryApplication());
		if (iApplication == nil) break;
		
		InterfacePtr<IDialogMgr> iDialogMgr(iApplication, ::UseDefaultIID());
		if (iDialogMgr == nil) break;

		iDialogMgr->SetSuppressDialogs(KESSDIdleTask::flg);

	} while (false);

	// Removes the task from its queues.
	return IIdleTask::kEndOfTime;
}