
#include "Common.h"

bool Extension::TrueCondition(TCHAR * message)
{
	return true;
}

bool Extension::FalseCondition(TCHAR * message)
{
	return false;
}

bool Extension::FlagStatus(int number, int flag_index)
{
	int buffer_int = pow(2, flag_index);

	return ((number & buffer_int) == buffer_int);
}

bool Extension::BadObject()
{
	return true;
}

bool Extension::BadObjectTest()
{
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
	{
		return false;
	}

	else
	{
		return true;
	}
}