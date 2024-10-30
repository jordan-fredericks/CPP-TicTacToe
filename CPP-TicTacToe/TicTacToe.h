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

	bool IsGameOver() const 
	{
		//Check all 8 victory conditions
		if (m_board[0] == m_board[1] && m_board[1] == m_board[2]) 
		{ 
			Victor(m_board[0]);
			return true; 
		}
		else if (m_board[3] == m_board[4] && m_board[4] == m_board[5]) 
		{
			Victor(m_board[3]);
			return true;
		}
		else if (m_board[6] == m_board[7] && m_board[7] == m_board[8]) 
		{
			Victor(m_board[6]);
			return true;
		}
		else if (m_board[0] == m_board[3] && m_board[3] == m_board[6]) 
		{
			Victor(m_board[0]);
			return true;
		}
		else if (m_board[1] == m_board[4] && m_board[4] == m_board[7]) 
		{
			Victor(m_board[1]);
			return true;
		}
		else if (m_board[2] == m_board[5] && m_board[5] == m_board[8]) 
		{
			Victor(m_board[2]);
			return true;
		}
		else if (m_board[0] == m_board[4] && m_board[4] == m_board[8]) 
		{
			Victor(m_board[0]);
			return true;
		}
		else if (m_board[2] == m_board[4] && m_board[4] == m_board[6]) 
		{
			Victor(m_board[2]);
			return true;
		}
		//Check if all 9 spots on the board are taken if no victory condition is found
		else if (m_turn > 9) 
		{ 
			std::cout << "It's a tie\n"; 
			return true; 
		}
		//Return false if no victory or tie is found
		else { return false; }
	}

	//This function is to see which player won when a victory is found
	void Victor(char marker) const
	{
		if (marker == 'X') { std::cout << "Player 1 wins!\n"; }
		else { std::cout << "Player 2 wins!\n"; }
	}

	void Display() const
	{
		system("cls");
		std::cout << m_board[0] << "|" << m_board[1] << "|" << m_board[2] << "\n";
		std::cout << "-----\n";
		std::cout << m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n";
		std::cout << "-----\n";
		std::cout << m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
	}

	void TakeTurn()
	{
		int choice = 0;
		char marker = 'Q';

		std::cout << "Player " << m_player << "'s turn.\n";

		//Assigns player 1 the X and player 2 the O
		if (m_player == 1) { marker = 'X'; }
		else { marker = 'O'; }

		while (choice < 1 || choice > 9)
		{
			std::cout << "Where would you like to place your piece: ";
			std::cin >> choice;
			//Checks if that spot is on the board
			if (choice < 1 || choice > 9) { std::cout << "Please place your piece on the board.\n"; }
			//Checks if that spot is already taken
			else if (m_board[choice - 1] == 'X' || m_board[choice - 1] == 'O') 
			{ 
				std::cout << "Please place your piece on an empty spot.\n"; 
				choice = 0;
			}
			//If the spot chosen is on the board and not already taken, place the marker down
			else { m_board[choice - 1] = marker; }
		}

		//Change the active player at the end of the turn
		if (m_player == 1) { m_player = 2; }
		else { m_player = 1; }

		//Increment the turn counter
		m_turn += 1;
	}

};