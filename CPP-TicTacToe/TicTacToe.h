#pragma once

#include "Game.h"
#include <iostream>
#include <conio.h>

class TicTacToe : public Game
{
private:

	char m_board[9] = {'1','2','3','4','5','6','7','8','9'};
	int m_player = 1;
	//This variable is used as an easy way to find if a tie happened
	int m_turn = 1;

public:

	//Constructor
	TicTacToe() { }

	//Destructor
	~TicTacToe() { }

	bool IsGameOver() const;

	//This function is to see which player won when a victory is found
	void Victor(char marker) const;

	void Display() const;

	void TakeTurn():

};