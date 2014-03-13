
#include "Common.h"

unsigned int Extension::Modulus(int x, int y)
{

	if (y == 0)
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

long Extension::FindPrime(int number,  int nth_number)
{
	long count = 0;
	bool swap = false;

	if(nth_number <= 0)
	{
		nth_number = 1;
	}

	while(count < nth_number)
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

		++number;

	}

	return (number-1);
}

void Extension::ExpressionComment(TCHAR * message)
{
}

byte Extension::Sign(int number)
{
	if(number < 0)
	{
		return -1;
	}

	else if(number > 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
	
}

int Extension::EventNum()
{
	return -1;
}

float Extension::ObjectAngle()
{
	return GetSpriteAngle(rdPtr,(npSpr)Extension::HandlerObject->rs,0);
}
