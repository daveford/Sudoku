/******************************************************************************
Cluster.cpp
The Cluster class reresents 9 Squares
They will arranged in either a Column, Row, or Box
******************************************************************************/
#include "Cluster.hpp"

const char* Cluster::ClusterName[] = { "Row", "Column", "Box" };

Cluster::Cluster(ClusterType type, Square** s)
{
	this->type = type;
	for(int k=0; k<9; k++)
	{
		this->sq[k] = s[k];
		s[k]->addCluster(this);
	}
}


/*-----------------------------------------------------------------------------
print function
Prints the type of Cluster and all the Squares in the cluster
-----------------------------------------------------------------------------*/
void Cluster::print(ostream& out)
{
	out << ClusterName[type] << endl;
	for(int j=0; j<9; j++) &sq[j]->print(out);
	out << endl;
}


/*-----------------------------------------------------------------------------
shoop function
takes a square and a char as parameters
turns off the possible bit for the char value that is passed for all
square's in the cluster, except the square that is passed, which value is
the char that is passed in.
-----------------------------------------------------------------------------*/
void Cluster::shoop(Square* s, char val)
{
	for(int k=0; k<9; k++)
	{
		if(&s != &sq[k]) sq[k]->turnOff(val-'0');
	}
}