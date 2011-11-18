/*-----------------------------------------------------------------------------
This class represents the Suduko board and all of it components
-----------------------------------------------------------------------------*/
#pragma once
#include "tools.hpp"
#include "Square.hpp"
#include "Cluster.hpp"

class Board
{
private:
	ifstream in;
	Square sq[81];
	Cluster*  cl[27];
public:

	//constructor
	Board(const char* file);

	//destructor
	~Board();

	//functions
	Square& sub(int j, int k);
	void print(ostream&);
};

inline ostream& operator << (ostream& out, Board& b)
{
	b.print(out);
	return out;
}