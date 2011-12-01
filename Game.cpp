/*-----------------------------------------------------------------------------
All the functions of the Game class
-----------------------------------------------------------------------------*/
#include "Game.hpp"

//constructor
Game::Game(const char* out, const char* in): output(out), input(in)
{
	b = new Board(in);
}
//display the menu
char
Game::Menu()
{
	char select;
	cout << "Please select what you want to do" << endl
		 << "a) Move" << endl
		 << "b) Turn Off" << endl
		 << "c) Save" << endl
		 << "d) Restore" << endl
		 << "e) Undo" << endl
		 << "Press q to exit" << endl
		 << ": ";
	cin >> select;
	return select;
}

/*-----------------------------------------------------------------------------
Take the selected character from the user and rout the flow
of the program to the correct action
-----------------------------------------------------------------------------*/
void
Game::Action(char c)
{
	switch(c)
	{
		case 'a':
			cout << "You chose to move." << endl << endl;
			break;
		case 'b':
			cout << "You chose to Turn Off." << endl << endl;
			break;
		case 'c':
			cout << "You chose save." << endl << endl;
			PushFrame();
			break;
		case 'd':
			cout << "You chose Restore." << endl << endl;
			PopFrame();
			break;
		case 'e':
			cout << "You chose Undo." << endl << endl;
			break;
		defualt:
			cout << "This is an invalid selection!" << endl << endl;
			break;
	}
}

/*-----------------------------------------------------------------------------
Push the current Frame onto the stack
-----------------------------------------------------------------------------*/
void
Game::PushFrame()
{
	b->saveState(&cur);
	frames.push(&cur);
}

/*-----------------------------------------------------------------------------
Pop the Frame off the stack and call restoreState() in the Board class
-----------------------------------------------------------------------------*/
void
Game::PopFrame()
{
	cur = *(frames.pop());
	b->restoreState(&cur);
}