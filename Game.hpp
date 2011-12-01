/*-----------------------------------------------------------------------------
This class has the input file for the game, the output file to save the game
It also keeps the stack of game states so users can undo moves
This also has the user interface for the game
-----------------------------------------------------------------------------*/
#pragma once
#include "tools.hpp"
#include "StackT.hpp"
#include "Board.hpp"
#include "Frame.hpp"
//#include "SquareState.hpp"

class Game
{
private:
	const char* output;
	const char* input;
	Stack<Frame*> frames;
	Frame cur;
	Board* b;
public:
	Game(){};
	Game(const char* out, const char* in);
	~Game(){};
	char Menu();
	void PushFrame();
	void PopFrame();
	void Action(char c);
};