
#include "Common.h"

void Extension::ActionComment(TCHAR * message)
{
}

void Extension::SetObject(LPRDATA object)
{
		StoredObject = object;
}

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

void Extension::ChangeAngle(int deltaAngle)
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

	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}

void Extension::IncrementX(int deltaX)
{
	if(IsObjectStillValid())
	{
		ObjectChanged();
		StoredObject->rHo.hoX += deltaX;
	}
	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}

void Extension::IncrementY(int deltaY)
{
	if(IsObjectStillValid())
	{
		ObjectChanged();
		StoredObject->rHo.hoY += deltaY;
	}
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


void Extension::ObjectChanged()
{
	((LPRO)StoredObject)->roc.rcChanged = true;
}