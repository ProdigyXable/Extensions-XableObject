
#include "Common.h"

// Properly returns the circular modulus of negatives numbers
unsigned int Extension::Modulus(int dividend, int divisor)
{
	if (divisor <= 1)
	{
		return 0;
	}

	// Ensures X is positive before the modulus operation
	else if (dividend < 0)
	{
		do
		{
			dividend += abs(divisor);
		}
		while(dividend < 0);
	}

	if (dividend >= 0)
	{
		return (dividend % divisor);
	}

	return 0;
	

}

// Converts a base positive 10 number to a specified based, works best with 2 - 16 base, extendable to base 36
// Not intended for negative numbers
TCHAR * Extension::BaseConversionString(int number, int base)
{
	const int asciiValueForA = 65;
	const int maxBase = 36;

	if(number <= 0)
	{
		TCHAR * New = (TCHAR *) Runtime.Allocate(2);
		New[0] = '0';
		New[1] = '\0';

		return New;
	}

	if(base < 2)
	{
		base = 2;
	}

	else if(base > maxBase)
	{
		base = maxBase;
	}

 	int maxLength =  pow( base, floor( log( number ) / log( base ) ) );
	int index = 0;
	
	TCHAR * New = (TCHAR *) Runtime.Allocate( maxLength + 1 );

	while( maxLength > 0 )
	{
		if( ( number / maxLength ) % base < 10 )
		{
			New[index] = (TCHAR)( ( ( number / maxLength ) % base ) + 48 );
		}

		else if( ( (number / maxLength ) % base >= 10)  && ( ( number / maxLength ) % base < maxBase ))
		{
			New[index] = (TCHAR)( asciiValueForA + ( ( ( number / maxLength ) % base ) - 10 ) );
		}

		index++;
		
		maxLength = (maxLength / base);
	}

	New[index] = '\0';
	return New;
}

// Allows you to find the nth prime number after an initial number
long Extension::FindPrime(int initialNumber,  int nth_number)
{
	long count = 0;
	bool detect = false;

	// Error Checking
	if(nth_number <= 0)
	{
		nth_number = -1;
	}

	// Implments lower limit on initial number
	initialNumber = max(2,initialNumber);

	while(count < nth_number)
	{
		if(Extension::PrimeTest(initialNumber))
		{
			count++;
		}

		initialNumber++;
	}

	return (initialNumber - 1);
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

	// Unforseen input such as -1.#IND. Anything getting here likely to crash program
	else
	{
		return -2;
	}
	
}

// Returns the current angle of an object modulus'ed 360 with any floating remainders
int Extension::ObjectAngle()
{
	if(isObjectStillValid())
	{
		
		if(isProductMMF2())
		{
			ANGLETYPE angleLeftovers = ((LPRO)StoredObject)->roc.rcAngle - (int)((LPRO)StoredObject)->roc.rcAngle;
			return angleLeftovers + Modulus(((LPRO)StoredObject)->roc.rcAngle, 360);
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
	if(isObjectStillValid())
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
	if(isObjectStillValid())
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
	if(number >= 0)
	{
		int * saved = new int[number + 1];
		saved[0] = 1;

		for(int n = 1; n <= number; n++)
		{
			saved[n] = saved[n-1] * n;
		}

		return saved[number];
	}

	else
	{
		return -1;
	}
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


float Extension::cartToPolarRadii(float X, float Y)
{
	return sqrt( pow(X,2) + pow(Y,2) );
}
float Extension::cartToPolarAngle(float X, float Y)
{
	return (180 / MATH_PI) * atan2f(Y,X);
}
float Extension::polarToCartX(float radius, float angle)
{
	return radius * cos(MATH_PI / 180 * angle);
}

float Extension::polarToCartY(float radius, float angle)
{
	return radius * sin(MATH_PI / 180  * (angle + MMFusionAngle_Shift));
}