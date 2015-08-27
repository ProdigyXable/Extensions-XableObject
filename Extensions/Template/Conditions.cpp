
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
	return StoredObject == rdPtr;
}

// Performance can be improved by hardcoding first 100, 1000, 10,000, etc... prime numbers into array
bool Extension::PrimeTest(int number)
{
	if(number <= 0)
	{
		return false;
	}

	// Base Case
	if(number == 2)
	{
		return true;
	}

	bool detected = false;

	// Removes half the possible checked numbers from the loop
	int max = sqrt(number) + 1;

	for(int index = 2; index <= max && !detected; index++)
	{
		
		if((number % index) == 0 )
		{
			detected = true;
		}
	}
		
	return !detected;
}

bool Extension::BadAngleInput()
{
	return true;
}