//Josiah Lovin
//TicTacToe.cpp: Simulates a game of Tic-Tac-Toe

#include<iostream>
#include "TicTacToe.h"

using namespace std;

//Constructor sets array to spaces
TicTacToe::TicTacToe()
{
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[0].size(); ++j)
		{
			board[i][j] = static_cast<int>(' ');
		}
	}
}

//simulates a TicTacToe move
void TicTacToe::makeMove()
{
	char turn{'X'};
	bool cont{true};
	//play until game is won or is a draw
	while(cont)
	{
		printBoard();
		cont = xoMove(static_cast<int>(turn));
		turn == 'X' ? turn = 'O' : turn = 'X';
	}
	turn == 'X' ? turn = 'O' : turn = 'X';
	printBoard();
	//output game result
	gameStatus() == WIN ? cout << "Player " << turn << " wins!" : cout << "It's a draw!";
}

//prints the board on the screen
void TicTacToe::printBoard() const
{
	cout << "     |     |     " << endl;
	cout << "  " << static_cast<char>(board[0][0]) << "  |  " << static_cast<char>(board[0][1]) << "  |  " << static_cast<char>(board[0][2]) << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << static_cast<char>(board[1][0]) << "  |  " << static_cast<char>(board[1][1]) << "  |  " << static_cast<char>(board[1][2]) << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << static_cast<char>(board[2][0]) << "  |  " << static_cast<char>(board[2][1]) << "  |  " << static_cast<char>(board[2][2]) << "  " << endl;
	cout << "     |     |     " << endl;
}

//executes the move
bool TicTacToe::xoMove(int tur)
{
	int row{0};
	int column{0};
	cout << "Player " << static_cast<char>(tur) << "'s turn: ";
	cin >> row >> column;
	//prompt for move until valid
	while(!validMove(row, column))
	{
			cout << "Please enter a valid move: ";
			cin >> row >> column;
	}
	board[row][column] = tur;
	//check if game should continue
	if(gameStatus() == CONTINUE)
	{
		return true;
	}
	return false;
}

//checks if move is valid
bool TicTacToe::validMove(int ro, int co) const
{
	if(board[ro][co] == static_cast<int>(' '))
	{
		return true;
	}
	return false;
}

//checks if game is won, a draw, or continues
TicTacToe::Status TicTacToe::gameStatus() const
{
	//check if there is a winner
	if(((board[0][0] == board[0][1]) && (board[0][0] == board[0][2]) && (board[0][0] != static_cast<char>(' '))) ||
	   ((board[1][0] == board[1][1]) && (board[1][0] == board[1][2]) && (board[1][0] != static_cast<char>(' '))) ||
	   ((board[2][0] == board[2][1]) && (board[2][0] == board[2][2]) && (board[2][0] != static_cast<char>(' '))) ||
	   ((board[0][0] == board[1][0]) && (board[0][0] == board[2][0]) && (board[0][0] != static_cast<char>(' '))) ||
	   ((board[0][1] == board[1][1]) && (board[0][1] == board[2][1]) && (board[0][1] != static_cast<char>(' '))) ||
	   ((board[0][2] == board[1][2]) && (board[0][2] == board[2][2]) && (board[0][2] != static_cast<char>(' '))) ||
	   ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && (board[0][0] != static_cast<char>(' '))) ||
	   ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != static_cast<char>(' '))))
	{
		return WIN;
	}
	//check for empty spaces
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[0].size(); ++j)
		{
			if(board[i][j] == static_cast<int>(' '))
			{
				return CONTINUE;
			}
		}
	}
	return DRAW;
}