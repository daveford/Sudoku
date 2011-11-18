//-----------------------------------------------------------------------------
//Square.hpp
//
#pragma once
#include "tools.hpp"
#include "SquareState.hpp"
#include <vector>
class Cluster;
typedef short int sInt;
typedef unsigned short int usInt;

class Square: public SquareState{
private:
	sInt row, col;
	vector<Cluster*> cluster;
	vector<Cluster*>::iterator scan;
public:
	//constructor prototype
	Square();
	Square(sInt row, sInt col);

	//descructor inline function
	~Square(){/* cout << "Deleted square " << row << ", " << col << "\n";*/ };

	//get functions
	//mostly used for testing
	//char getValue(){ return value; };

	//function prototypes
	ostream& print( ostream& );
	void addCluster(Cluster* c);
};

inline ostream& operator << (ostream& out, Square& sq)
{
	sq.print(out);
	return out;
}