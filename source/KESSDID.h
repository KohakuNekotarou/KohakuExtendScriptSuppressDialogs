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


#ifndef __KESSDID_h__
#define __KESSDID_h__

#include "SDKDef.h"

// Company:
#define kKESSDCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESSDCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESSDPluginName	"KohakuExtendScriptSuppressDialogs"			// Name of this plug-in.
#define kKESSDPrefixNumber	0x204650 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESSDVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESSDAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESSDPrefixNumber above to modify the prefix.)
#define kKESSDPrefix		RezLong(kKESSDPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESSDStringPrefix	SDK_DEF_STRINGIZE(kKESSDPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESSDMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESSDMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESSDPluginID, kKESSDPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESSDScriptProviderBoss, kKESSDPrefix + 0)

// InterfaceIDs:
DECLARE_PMID(kInterfaceIDSpace, IID_IKESSDIDLETASK, kKESSDPrefix + 0)

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESSDScriptProviderImpl, kKESSDPrefix + 0)
DECLARE_PMID(kImplementationIDSpace, kKESSDIdleTaskImpl, kKESSDPrefix + 1)

// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESSDAboutActionID, kKESSDPrefix + 0)

//Script Element IDs
DECLARE_PMID(kScriptInfoIDSpace, kKESSDSuppressDialogsMethodScriptElement, kKESSDPrefix + 0)

// "About Plug-ins" sub-menu:
#define kKESSDAboutMenuKey			kKESSDStringPrefix "kKESSDAboutMenuKey"
#define kKESSDAboutMenuPath		kSDKDefStandardAboutMenuPath kKESSDCompanyKey

// "Plug-ins" sub-menu:
#define kKESSDPluginsMenuKey 		kKESSDStringPrefix "kKESSDPluginsMenuKey"
#define kKESSDPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESSDCompanyKey kSDKDefDelimitMenuPath kKESSDPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESSDAboutBoxStringKey	kKESSDStringPrefix "kKESSDAboutBoxStringKey"
#define kKESSDTargetMenuPath kKESSDPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESSDFirstMajorFormatNumber  RezLong(1)
#define kKESSDFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESSDCurrentMajorFormatNumber kKESSDFirstMajorFormatNumber
#define kKESSDCurrentMinorFormatNumber kKESSDFirstMinorFormatNumber

#endif // __KESSDID_h__
