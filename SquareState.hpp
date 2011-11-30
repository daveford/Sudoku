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
	sInt psblCount;
	usInt psblBit;
	char Value;
public:
	SquareState() : psblCount(9), psblBit(0x03FE), Value('-') {};

	~SquareState() {};

	ostream& print( ostream& );
	virtual void turnOff(int n);
	virtual void mark(char c){Value = c;};
	virtual char getValue(){return Value;};
};

inline ostream& operator << (ostream& out, SquareState& sq)
{
	sq.print(out);
	return out;
}