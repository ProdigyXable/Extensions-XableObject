
#include "Common.h"

void Extension::ActionComment(TCHAR * message)
{
}

// Sets the store object based on the object picker within MMFusion
void Extension::SetObject(LPRDATA object)
{
		StoredObject = object;
}

// Sets the stored object based on a fixed value
// May cause crashes on certain objects (no such objects found)
void Extension::SetObjectFixedValue(int fixedvalue)
{
	LPRDATA buffer = (LPRDATA)this->Runtime.LPROFromFixed(fixedvalue);
	
		if(buffer != NULL)
		{
			StoredObject = buffer;
		}

		else
		{
			ClearObject();
		}
}

// Rotates the stored object by the specified angle
void Extension::ChangeAngle(float deltaAngle)
{
	if( IsObjectStillValid() )
	{
		if(IsProductMMF2())
		{
			ObjectChanged();
			((LPRO)StoredObject)->roc.rcAngle += deltaAngle;
		}

		// Due to some unknown change from MMF2 to Clickteam Fusion, rcAngle return an unknown value (possibly a pointer or a memory location)
		// As such, in Clickteam Fusion, this action does nothing. The stored object is not cleared
		else
		{
			return;
		}
	}

	// Invalid objects must be cleared. An error condition ("Is Object Bad") is also generated
	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}

// Changes the y-position of the stored object by the specified amount
void Extension::ChangeX(int deltaX)
{
	if(IsObjectStillValid())
	{
		ObjectChanged();
		StoredObject->rHo.hoX += deltaX;
	}

	// Invalid objects must be cleared. An error condition ("Is Object Bad") is also generated
	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}

// Changes the y-position of the stored object by the specified amount
void Extension::ChangeY(int deltaY)
{
	if(IsObjectStillValid())
	{
		ObjectChanged();
		StoredObject->rHo.hoY += deltaY;
	}

	// Invalid objects must be cleared. An error condition ("Is Object Bad") is also generated
	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}

// Sets the StoredObject to a value which will not modify any other object (setting to NULL crashes the application)
void Extension::ClearObject()
{
	StoredObject = rdPtr;
}

// Tells MMFusion the stored object is changed and needs to be redrawn to the screen
void Extension::ObjectChanged()
{
	((LPRO)StoredObject)->roc.rcChanged = true;
}