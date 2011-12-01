/*-----------------------------------------------------------------------------
Frame struct - keeps an array of 81 SquareStates
-----------------------------------------------------------------------------*/
#pragma once
#include "tools.hpp"
#include "SquareState.hpp"

struct Frame{
protected:
	SquareState frame[81];
public:
	SquareState& operator[] (int index) {return this->frame[index]; };
	//Frame operator[] (int index) {return frame[index]; };
	//SquareState* operator= (const SquareState* ss) { return ss; }; 
};