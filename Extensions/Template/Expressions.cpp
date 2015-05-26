
#include "Common.h"



// Properly returns the circular modulus of negatives numbers
unsigned int Extension::Modulus(int x, int y)
{

	if (y <= 1)
	{
		return 0;
	}

	// Ensures X is positive before the modulus operation
	else if (x < 0)
	{
		do
		{
			x += abs(y);
		}
		while(x < 0);
	}

	if (x >= 0)
	{
		return (x % y);
	}

	return 0;
	

}

// Converts a base 10 number to a specified based, works best with 2 - 16 base, extendable to base 36
TCHAR * Extension::BaseConversionString(int number, int base)
{
	if(base < 2)
	{
		base = 2;
	}

	else if(base > 36)
	{
		base = 36;
	}

 	int max =  pow(base,floor(log(number)/log(base)));
	int index = 0;
	
	TCHAR * New = (TCHAR *) Runtime.Allocate(max+1);

	while(max > 0)
	{
		if((number / max) % base < 10)
		{
			New[index] = (TCHAR)(((number / max) % base)+ 48);
		}

		else if(((number / max) % base >= 10) && ((number / max) % base < 36))
		{
			New[index] = (TCHAR)(65 + (((number / max) % base)-10));
		}

		index++;
		
		max = (max / base);
	}

	New[index] = '\0';
	return New;
}

// Allows you to find the nth prime number after an initial number
long Extension::FindPrime(int number,  int nth_number)
{
	long count = 0;
	bool detect = false;

	// Error Checking
	if(nth_number <= 0)
	{
		nth_number = -1;
	}

	number = max(2,number);

	while(count < nth_number)
	{
		if(Extension::PrimeTest(number))
		{
			count++;
		}

		number++;
	}

	return (number - 1);
}

// Allows you to put a custom comment into the Event Editor/Event List Editor
void Extension::ExpressionComment(TCHAR * message)
{
}

// Returns the sign of a number and 0 if 0. Crashes if input is "-1.#IND"
byte Extension::Sign(double number)
{
	if(number < 0)
	{
		return -1;
	}

	else if(number > 0)
	{
		return 1;
	}

	else if(number == 0)
	{
		return 0;
	}

	else
	{
		return -2;
	}
	
}

// Returns the current angle of an object modulus'ed 360 with any floating remainders
int Extension::ObjectAngle()
{
	
	if(IsObjectStillValid())
	{
		
		if(IsProductMMF2())
		{
			ANGLETYPE leftovers = ((LPRO)StoredObject)->roc.rcAngle - (int)((LPRO)StoredObject)->roc.rcAngle;
			return leftovers + Modulus(((LPRO)StoredObject)->roc.rcAngle, 360);
		}

		// Due to diffculties in the rcAngle, this expression does not work in Clickteam Fusion.
		// So an error code is returned
		else
		{
			return -2;
		}
	}

	else
	{
		Runtime.GenerateEvent(InvalidObject);
		return -1;
	}
}

// Turns on the nth bit of a number. Bit index must be from 0 - 31.
int Extension::IntBitFlagOn(int number, int bit_index)
{
	bit_index = max(pow(2,min(31,bit_index)),0);

	return (number | bit_index);
}

// Turns off the nth bit of a number. Bit index must be from  0 - 31.
int Extension::IntBitFlagOff(int number, int bit_index)
{
	bit_index = max(pow(2,min(31,bit_index)),0);
	
	return (number & (~bit_index));

}

// Toggles the nth bit of a number. Bit index must be from 0 - 31
int Extension::IntBitFlagToggle(int number, int bit_index)
{
	bit_index = max(pow(2,min(31,bit_index)),0);

	return (number ^ bit_index);
}

// Returns the X position of the stored object
int Extension::ObjectX()
{
	if(IsObjectStillValid())
	{
		return StoredObject->rHo.hoX;
	}

	else
	{
		Runtime.GenerateEvent(InvalidObject);
		return -1;
	}
}

// Returns the Y position of the stored object
int Extension::ObjectY()
{
	if(IsObjectStillValid())
	{
		return StoredObject->rHo.hoY;
	}

	else
	{
		Runtime.GenerateEvent(InvalidObject);
		return -1;
	}
}

int Extension::Factorial(int number)
{
	if(number <= 1)
	{
		return 1;
	}
	return number * Factorial(number - 1);
}

int Extension::FiboNumber(int number)
{
	if(number > 1)
	{
		int * saved = new int[number + 1];
		saved[0] = 0;
		saved[1] = 1;

		for(int i = 2; i <= number; i++)
		{
			saved[i] = saved[i-2]+saved[i-1];
		}

		return saved[number];

	}
	else if(number == 0 )
	{
		return 0;
	}

	else if (number == 1)
	{
		return 1;
	}

	else
	{
		return -1;
	}
}

int Extension::ObjectFixedValue()
{
	return this->Runtime.FixedFromLPRO( (LPRO)StoredObject);
}