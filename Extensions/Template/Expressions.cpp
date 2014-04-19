
#include "Common.h"

// Properly returns the circular modulus of negatives numbers
unsigned int Extension::Modulus(int x, int y)
{

	if (y <= 1)
	{
		return 0;
	}

	if (x < 0)
	{
		do
		{
			x += abs(y);
		}
		while(x < 0);
	}

	if (x >= 0)
	{
		return (x % abs(y));
	}

	return 0;
	

}

// Converts a base 10 number to a specified based, works best with 2 - 16 base
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
			New[index] = (char)(((number / max) % base)+ 48);
		}

		else if(((number / max) % base >= 10) && ((number / max) % base < 36))
		{
			New [index] = (char)(65 + (((number / max) % base)-10));
		}

		index++;
		
		max = (max / base);
	}

	New[index] = '\0';
	return New;
}

// Allows you to find the nth prime number after a initial number
long Extension::FindPrime(int number,  int nth_number)
{
	long count = 0;
	bool swap = false;

	if(nth_number <= 0)
	{
		nth_number = 1;
	}

	if(number == -1 || number == 0 || number == 1)
	{
		if(nth_number > 0)
		{
			number++;
		}

		if(nth_number < 0)
		{
			number--;
		}
	}
		
	while(count < nth_number && nth_number != 0)
	{
		swap = false;

		for(int holdingValue = 2; holdingValue < abs(number)-1; ++holdingValue)
		{
			
			if(abs(number) % holdingValue == 0 )
			{
				swap = true;
				break;
			}
			
			if(swap)
			{
				break;
			}
		}

		if(swap == false && (number != 0  && abs(number )!= 1))
		{
			++count;
		}

		if(nth_number > 0)
		{
			++number;
		}

		if(nth_number < 0)
		{
			--number;
		}

	}

	if(nth_number > 0)
	{
		return (number - 1);
	}

	else if(nth_number < 0)
	{
		return (number + 1);
	}

	else
	{
		return 0;
	}
	
}

// Allows you to put a custom comment into the Event Editor/EventListEditor
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

	else if( number = 0)
	{
		return 0;
	}

	else
	{
		return -2;
	}
	
}

// Not used at all
int Extension::EventNum()
{
	return -1;
}

// Returns the current angle of an object
float Extension::ObjectAngle()
{
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
	{
		float leftovers = ((LPRO)StoredObject)->roc.rcAngle - (int)(((LPRO)StoredObject)->roc.rcAngle);
		return leftovers + Extension::Modulus(((LPRO)StoredObject)->roc.rcAngle, 360);
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
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
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
	if((((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != NULL)
	{
		return StoredObject->rHo.hoY;
	}

	else
	{
		Runtime.GenerateEvent(InvalidObject);
		return -1;
	}
}