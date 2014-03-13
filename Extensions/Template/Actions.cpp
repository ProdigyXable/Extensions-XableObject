
#include "Common.h"


void Extension::ActionComment(TCHAR * message)
{

}

void Extension::SetObject(LPRDATA object)
{
	
		Extension::HandlerObject = object;
}

void Extension::IncrementX(int deltaX)
{
	if(Runtime.FixedFromLPRO((LPRO)Extension::HandlerObject))
	{
		callRunTimeFunction(Extension::HandlerObject, RFUNCTION_SETPOSITION, Extension::HandlerObject->rHo.hoX + deltaX, Extension::HandlerObject->rHo.hoY);
		ObjectChanged();
	}
	else
	{
		ClearObject();
	}
}
void Extension::IncrementY(int deltaY)
{
	if(Runtime.FixedFromLPRO((LPRO)Extension::HandlerObject))
	{
		callRunTimeFunction(Extension::HandlerObject, RFUNCTION_SETPOSITION, Extension::HandlerObject->rHo.hoX,	Extension::HandlerObject->rHo.hoY + deltaY);
		ObjectChanged();
	}
	else
	{
		ClearObject();
	}
}

void Extension::ClearObject()
{
	Extension::HandlerObject = NULL;
}

void Extension::ObjectChanged()
{
//	Extension::HandlerObject->rc->rcChanged = true;
}

void Extension::ChangeAngle(float deltaAngle)
{
	if(Runtime.FixedFromLPRO((LPRO)Extension::HandlerObject))
	{
	LPRO Object = (LPRO)Extension::HandlerObject;
	float ObjectAngle = Object->roc.rcOldAngle;

	SetSpriteAngle(rhPtr->rhIdAppli,(npSpr)Extension::HandlerObject->rs, 120, 1);

	}
}