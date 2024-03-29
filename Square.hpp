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
	char getValue(){ return SquareState::getValue(); };

	//function prototypes
	ostream& print( ostream& );
	void turnOff(int n);
	void mark(char c);
	void addCluster(Cluster* c);
	SquareState* GetState(){return (SquareState*) this;};
};

inline ostream& operator << (ostream& out, Square& sq)
{
	sq.print(out);
	return out;
}