/*----------------------------------------------------------------------------/
/This is a test of all the functions in the Square class
/----------------------------------------------------------------------------*/
#include "Square.hpp"
#include "Board.hpp"
#include "Cluster.hpp"
#include "Frame.hpp"
#include "Game.hpp"
//#include "UnitTest++.h"

void testSquare();
void testBoard();
void testCluster();
void testGame();

int main(int argc, const char* argv[])
{
	//redirec cout to the file output.txt
	/*ofstream file("output.txt");
	streambuf* buf = cout.rdbuf();
	cout.rdbuf(file.rdbuf());*/

	banner();
	testBoard();
	testGame();
	//testSquare();
	//testCluster();
	bye();

	//redirect cout to screen
	//cout.rdbuf(buf);
	return 0;
}


/*----------------------------------------------------------------------------/
/Function to perform all tests on the Square object
/All tests are outlined in SquareTestPlan.pdf
/----------------------------------------------------------------------------*/
void testSquare()
{
	//test that the constructor is creating the object
	Square test1 = Square(1, 1);
	//if(sizeof(test1) == NULL) cout << "Square constructor returned a NULL object, test1 failed\n";
	test1.mark('9');
	test1.turnOff(2);
	test1.turnOff(5);

	//test inputs that are less than 0
	Square test2 = Square(-1, -2);
	Square test3 = Square(5, -6);
	Square test4 = Square(-32000, 8);

	//test inputs larger than 8
	Square test8 = Square(10, 10);
	Square test9 = Square(2, 32000);
	Square test10 = Square(700, 6);

	//test print function with good ouput stream
	//and with a bad output stream
	//filebuf buffer;
	//ostream& out = ostream(&buffer);
	//buffer.open("test.txt", ios::in);
	//test1.print(out);
	test1.print(cout);
}

/*-----------------------------------------------------------------------------
Function to perform all the tests on the Board object
-----------------------------------------------------------------------------*/
void testBoard()
{
	char temp;
	Frame f;
	//Board b = Board("file.txt"); //file does not exist
	Board* b1 = new Board("input.txt");
	
	b1->print(cout);
	
	b1->saveState(&f);
	
	b1->sub(1,1).mark('2');
	b1->sub(1,2).mark('6');
	b1->sub(3, 6).mark('3');
	b1->sub(2, 1).mark('9');
	b1->sub(7, 5).mark('5');
	b1->sub(8, 8).mark('1');
	b1->sub(4, 8).mark('4');
	b1->sub(5, 6).mark('7');

	b1->print(cout);

	b1->restoreState(&f);

	b1->print(cout);
}

/*-----------------------------------------------------------------------------
Function to test the Cluster class
-----------------------------------------------------------------------------*/
void testCluster()
{
	Square* sq[9];
	for(int k=0; k<9; k++)
	{
		sq[k] = new Square(5, k+1);
	}
	Cluster cl = Cluster(Col, sq);
	sq[4]->mark('4');
	sq[7]->mark('1');
	sq[8]->mark('7');
	//cl.shoop(sq[4], '4');
	cout << cl;
}

/*-----------------------------------------------------------------------------
Function to test the game class
-----------------------------------------------------------------------------*/
void testGame()
{
	char c;
	Game g = Game("output.txt", "input.txt");
	while(c != 'q')
	{
		c = g.Menu();
		g.Action(c);
	}
}