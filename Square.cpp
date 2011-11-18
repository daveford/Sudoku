//-----------------------------------------------------------------------------
#include "Square.hpp"
#include "Cluster.hpp"



/*-----------------------------------------------------------------------------
Constructor takes two short ints as parameters
One for the row and one for the column.
Value defualts to '-'
-----------------------------------------------------------------------------*/
Square::Square(): row(0), col(0)
{
	cluster.reserve(3);
}


Square::Square(sInt row, sInt col): row(row), col(col)
{
	cluster.reserve(3);
}

/*-----------------------------------------------------------------------------
The print function for the Square class
Prints in the form "Square [(row#), (col#)] Value: (value)"
-----------------------------------------------------------------------------*/
ostream& Square::print(ostream& st)
{
	//st = SquareState::print(st);
	st << "Square [" << row << ", " << col << "] ";
	//if(!st){ cout << "Invalid output stream." << endl; return st; }
	SquareState::print(st);
	st << endl;
	return st;
}

/*-----------------------------------------------------------------------------
Set the value with the new value
Then make readjust neighbors
-----------------------------------------------------------------------------*/
void Square::mark(char value)
{
	SquareState::mark(value);
	for(scan = cluster.begin(); scan<cluster.end(); scan++)
		(*scan)->shoop(this, value);
}

/*-----------------------------------------------------------------------------
turn off the position, n, in the squares possibility list
-----------------------------------------------------------------------------*/
void Square::turnOff(int n)
{
	SquareState::turnOff(n);
	/*sInt mask = 1;
	mask <<= n;
	psblBit = ~mask & psblBit;
	psblC--;*/
}

/*-----------------------------------------------------------------------------
Add Cluster
Takes a Cluster* as a parameter and adds it to the vector containing all
the clusters that the Square is a part of
-----------------------------------------------------------------------------*/
void Square::addCluster(Cluster* c)
{
	cluster.push_back(c);
}