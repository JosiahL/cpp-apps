//Josiah Lovin
//mastermind.cpp
/*
    Desc:   program simulates a game of mastermind
    Input:  user enters the desired difficulty and enters guesses
    Output: various messages to help the user play the game
*/
#include<array>
#include<iostream>
#include<time.h>
using namespace std;
//function prototypes
void createKey(array<char, 6>&, int, char);
bool runGuesses(array<char, 6>, int, char);
string checkResult(array<char, 6>, array<char, 6>, int);
//function main begins program execution
int main()
{
	//initialize variables
	array<char, 6> key;
	bool play{true};
	bool won{false};
	char difficulty{'e'};
	char playAgain{'y'};
	int size{4};
	int wins{0};
	int attempts{0};
	string name{""};
	//output opening message
	cout << "Welcome to Mastermind! What is your name? ";
	cin >> name;
	cout << "Welcome, " << name << "!" << endl;
	//loop through game until user is done playing
	while(play)
	{
		++attempts;
		cout << "Would you like to play easy, average, or hard? (e/a/h): ";
		cin >> difficulty;
		if(difficulty=='h')
			size = 6;
		//create the mastercode
		createKey(key, size, difficulty);
		//Output game information
		if(difficulty=='e')
		{
			cout << "There are 4 distinct colors (ROYG) and 4 pegs." << endl;
			cout << "You get 10 guesses." << endl;
		}
		else if(difficulty=='a')
		{
			cout << "There are 6 distinct colors (ROYGBP) and 4 pegs." << endl;
			cout << "You get 12 guesses." << endl;
		}
		else
		{
			cout << "There are 8 distinct colors (ROYGBPTS) and 6 pegs." << endl;
			cout << "You get 15 guesses." << endl;
		}
		//let user guess
		won = runGuesses(key, size, difficulty);
		//output results
		if(won)
		{
			++wins;
			cout << "You win! Good job, " << name << "!" << endl;
		}
		else
			cout << "You lost! Good try, " << name << "!" << endl;
		cout << "You have won " << wins << " out of " << attempts << " game(s)." << endl;
		//ask user if they would like to continue playing
		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;
		if(playAgain=='n')
			play = false;
	}
	return 0;
}
//Desc: function creates the mastercode
//Post: arr gets a random mastercode
void createKey(array<char, 6>& arr, int num, char ch)
{
	//seed rand
	srand(static_cast<unsigned int>(time(0)));
	//initialize variables
	array<int, 5> used{8, 8, 8, 8, 8};
	bool again{true};
	int randInt{0};
	//produce a random int until it is unique
	for(int i=0; i<num; ++i)
	{
		while(again)
		{
			again = false;
			if(ch=='e')
				randInt = rand() % 4;
			else if(ch=='a')
				randInt = rand() % 6;
			else
				randInt = rand() % 8;
			for(int j=0; j<num; ++j)
			{
				if(randInt==used[j])
					again = true;
			}
		}
		used[i] = randInt;
		//assign a color
		switch(randInt)
		{
			case 0: arr[i] = 'R';
					break;
			case 1: arr[i] = 'O';
					break;
			case 2: arr[i] = 'Y';
					break;
			case 3: arr[i] = 'G';
					break;
			case 4: arr[i] = 'B';
					break;
			case 5: arr[i] = 'P';
					break;
			case 6: arr[i] = 'T';
					break;
			case 7: arr[i] = 'S';
					break;
		}
		again = true;
	}
}
//Desc:   function runs the part of the game where the user is guessing
//Input:  user inputs guesses
//Output: various messages helping the user play the game
//Return: true if the user wins the game, else return false
bool runGuesses(array<char, 6> arr, int num, char ch)
{
	//initialize variables
	array<char, 6> guess;
	bool duplicate{true};
	int numOfTurns{0};
	string result{""};
	string turn{""};
	if(ch=='e')
		numOfTurns = 10;
	else if(ch=='a')
		numOfTurns = 12;
	else
		numOfTurns = 15;
	//assign turn
	for(int i=0; i<numOfTurns; ++i)
	{
		switch(i)
		{
			case 0: turn = "first";
					break;
			case 1: turn = "second";
					break;
			case 2: turn = "third";
					break;
			case 3: turn = "fourth";
					break;
			case 4: turn = "fifth";
					break;
			case 5: turn = "sixth";
					break;
			case 6: turn = "seventh";
					break;
			case 7: turn = "eighth";
					break;
			case 8: turn = "ninth";
					break;
			case 9: turn = "tenth";
					break;
			case 10: turn = "eleventh";
					break;
			case 11: turn = "twelfth";
					break;
			case 12: turn = "thirteenth";
					break;
			case 13: turn = "fourteenth";
					break;
			case 14: turn = "fifteenth";
					break;
		}
		//check if user enters duplicates
		while(duplicate)
		{
			duplicate = false;
			cout << "Please enter your " << turn << " guess: ";
			if(ch=='h')
				cin >> guess[0] >> guess[1] >> guess[2] >> guess[3] >> guess[4] >> guess[5];
			else
				cin >> guess[0] >> guess[1] >> guess[2] >> guess [3];
			for(int i=0; i<num-1; ++i)
			{
				for(int j=i+1; j<num; ++j)
				{
					if(guess[i]==guess[j])
						duplicate = true;
				}
			}
			if(duplicate)
				cout << "No duplicates please." << endl;
		}
		duplicate = true;
		//check the guess against the key
		result = checkResult(arr, guess, num);
		//return true if user wins
		if(result == "You won!")
			return true;
		//return false if the user used all of their turns
		//else let the user guess again
		else
		{
			cout << result << endl;
			if(numOfTurns==(i+1))
				return false;
			cout << "You have " << numOfTurns - (i+1) << " guesses remaining." << endl;
		}
	}
}

//Desc:   function checks the user code against the master code and returns a
//        string that represents the pegs
//Return: the number of black and white pegs or "You win!" if the user wins the game
string checkResult(array<char, 6> arr1, array<char, 6> arr2, int num)
{
	//initialize pegs
	int black{0};
	int white{0};
	for(int i=0; i<num; ++i)
	{
		for(int j=0; j<num; ++j)
		{
			if(arr1[i]==arr2[j])
			{
				if(i==j)
					++black;
				else
					++white;
			}
		}
	}
	if(black==num)
		return "You won!";
	else
		return to_string(black) + " black, " + to_string(white) + " white";
}
