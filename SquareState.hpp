/*-----------------------------------------------------------------------------
SquareState.h
Contains the state of the game at the time it was saved.
Has the value at the time, the count of possible choices
and the list of possible choices
-----------------------------------------------------------------------------*/
#pragma once
#include "tools.hpp"
typedef short int sInt;
typedef unsigned short int usInt;

class SquareState
{
protected:
	sInt PsblCount;
	usInt PsblBit;
	char Value;
public:
	SquareState() : PsblCount(9), PsblBit(0x03FE), Value('-') {};

	~SquareState() {};

	ostream& print( ostream& );
	virtual turnOff(int n);
	virtual mark(char c);
};

inline ostream& operator << (ostream& out, SquareState& sq)
{
	sq.print(out);
	return out;
}