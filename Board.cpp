/*-----------------------------------------------------------------------------
This class represnets the suduko board
it will contain an array of 81 squares, one for each square of a sudoku board
-----------------------------------------------------------------------------*/
#include "Board.hpp"

Board::Board(const char* file)
{
	in.open(file);
	if(!in) fatal("Could not open %s for reading\n", file);

	//int count=0;
	for(int k=0; k<9; k++)
	{
		for(int j=0; j<9; j++)
		{
			sq[(k*9)+j] = Square(k+1, j+1);
			//sub(k, j) = Square(k+1, j+1);
		}
	}
	
	Square* lineup[9];
	//create Clusters for Rows
	for(int r=0; r<9; r++)
	{
		for(int c=0; c<9; c++){ lineup[c] = &sub(r, c); }
		cl[r] = new Cluster(Row, lineup);
	}
	
	//create clusters of columns
	for(int r=0; r<9; r++)
	{
		for(int c=0; c<9; c++){ lineup[c] = &sq[c*9+r]; }
		cl[r+9] = new Cluster(Col, lineup);
	}
	
	//create Box Clusters
	int clCount = 18;
	for(int row=0; row<9; row+=3)
	{
		for(int col=0; col<9; col+=3)
		{	
			int rCount = row;
			int cCount = col;
			for(int bc=0; bc<9; bc++)
			{
				lineup[bc] = &sub(rCount, cCount++);
				if(cCount%3 == 0)
				{
					rCount++;
					cCount = col;
				}
			}
			cl[clCount++] = new Cluster(Box, lineup);
		}
	}
}

Board::~Board()
{
	for(int k=0; k<81; k++) sq[k].~Square();	
	in.close();
}

Square& Board::sub(int j, int k)
{
	if(j>8 || j<0 || k>8 || k<0)
	{
		cout << "Invalid input(" << j << ", " << k << ")" << endl;
	}
	return sq[(j*9)+k];
}

void Board::print(ostream& out)
{
	if(!out) fatal("Could not output to the specified stream");
	for(int k=0; k<81; k++) out << sq[k];
	for(int c=0; c<27; c++)
	{
		out << "-----------------------------------------------------" << endl;
		cl[c]->print(out);
		out << endl;
	}
}