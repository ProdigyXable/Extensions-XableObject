
#include "Common.h"


void Extension::ActionComment(TCHAR * message)
{

}

void Extension::SetObject(LPRDATA object)
{
	
		StoredObject = object;
}

void Extension::IncrementX(int deltaX)
{
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
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
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
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

void Extension::ClearObject()
{
	// StoredObject = NULL;
}

void Extension::ObjectChanged()
{
	((LPRO)StoredObject)->roc.rcChanged = true;
}

void Extension::ChangeAngle(float deltaAngle)
{
	if( (((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject)
	{
		ObjectChanged();
		((LPRO)StoredObject)->roc.rcAngle += (ANGLETYPE)deltaAngle;
	}
	else
	{
		Runtime.GenerateEvent(InvalidObject);
		ClearObject();
	}
}