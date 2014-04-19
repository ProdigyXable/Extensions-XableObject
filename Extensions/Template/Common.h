#pragma once

// #define TGFEXT       // TGF2, MMF2, MMF2 Dev
   #define MMFEXT       // MMF2, MMF2 Dev
// #define PROEXT       // MMF2 Dev only

#include    "Edif.h"
#include	"Resource.h"

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files

// -- Custom Shortcut Definitions --
#define StoredObject Extension::HandlerObject

// Shortcut to create the immediate condition 
#define InvalidObject 3

struct EDITDATA
{
	// Header - required
	extHeader		eHeader;
	bool propertychecked;

	// Object's data
//	short			swidth;
//	short			sheight;

};

#include "Extension.h"
