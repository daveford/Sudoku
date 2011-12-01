/*------------------------------------------------------------------------------
SquareState.cpp
-----------------------------------------------------------------------------*/
#include "SquareState.hpp"

/*-----------------------------------------------------------------------------
*
*Pre: A list of bits to represent all the possible values of the square
*Post: The bit that represents the value of n is turned off making the value
*	of n not a possible value
*Return:
*
-----------------------------------------------------------------------------*/
void SquareState::turnOff(int n)
{
	sInt mask = 1;
	mask <<= n;
	psblBit = ~mask & psblBit;
	psblCount--;
}

/*-----------------------------------------------------------------------------
*
*Pre: SquareState with a a value and a list of possible values
*Post: The value and possible values printed out
*Return: The output stream passed to the function is returned
*
-----------------------------------------------------------------------------*/
ostream& SquareState::print(ostream& out)
{
	sInt mask = 0x0001;
	usInt psblBit_copy = psblBit;
	out << "Value: " << Value << " ";
	out << "Possibilites: ";
	for(int k=1; k<=9; k++)
	{
		mask <<= 1;
		if((mask & psblBit_copy) != 0) out << k;
		else out << " ";
	}
	return out;
}