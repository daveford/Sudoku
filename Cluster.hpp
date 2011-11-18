/******************************************************************************
Cluster.hpp
The Cluster class reresents 9 Squares
They will arranged in either a Column, Row, or Box
******************************************************************************/
#pragma once
#include "tools.hpp"
#include "Square.hpp"
#include <iostream>
using namespace std;

enum  ClusterType { Row, Col, Box };

class Cluster
{
private:
	static const char* ClusterName[3];
	Square* sq[9];
	ClusterType type;

public:
	//constructor
	Cluster(enum ClusterType, Square**);

	//destructor
	~Cluster(){};

	void print(ostream&);
	void shoop(Square* s, char val);
};

inline ostream& operator<< (ostream& out, Cluster& c)
{
	c.print(out);
	return out;
}