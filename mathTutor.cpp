//Josiah Lovin
// MathTutor.cpp
/*
    Desc:   Program simulates a math tutor.
            The program quizzes the user on twelve different multiplication
            problems in which the multiplicand and the multiplier range from 1 - 12.
    Input:  User inputs answers to multiplication questions
    Output: Various message to help the user practice their multiplication
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//function prototypes
int generateFact(int, int);
void correctAnswer(int);
void incorrectAnswer(int);

//function main begins program execution
int main()
{
	//initializing variables
	string name{""};
	string play{""};
	int correct{0};
	int counter{0};
	int userAnswer{0};
	int randInt1{0};
	int randInt2{0};
	int randInt3{0};
	//prompt for user input
	cout << "Welcome to the multiplication tutor!" << endl;
	cout << "What is your name? ";
	cin >> name;
	cout << "Let's see how good you are at multiplication, " << name << endl;
	cout << "Would you like to practice your multiplication tables (yes/no)? ";
	cin >> play;
	//quiz user until sentinel is reached
	while(play=="yes")
	{
		correct = 0;
		for(unsigned int i=0; i<12; ++i)
		{
			counter = 0;
			//randomize with seed using time
			srand(static_cast<unsigned int>(time(0)));
			//quiz user on random numbers
			randInt1 = 1 + rand() % 12;
			randInt2 = 1 + rand() % 12;
			while(counter<3)
			{
				randInt3 = rand() % 4;
				userAnswer = generateFact(randInt1, randInt2);
				if(userAnswer == randInt1*randInt2)
				{
					++correct;
					correctAnswer(randInt3);
					counter = 3;
				}
				else
				{
					if(counter<2)
						incorrectAnswer(randInt3);
					++counter;
				}
			}
		}
		//display results of the quiz
		cout << name << ", you scored " << correct << " out of 12 points!\n" << endl;
		cout << "Would you like to practice your multiplication tables (yes/no)? ";
		cin >> play;
	}
	cout << "Thanks for playing " << name << "!";
	return 0;
}

//Desc:   asks the user a multiplication question
//Pre:    num1 and num2 are between [1,12]
//Input:  user enters their answer
//Output: "What is (1-12) * (1-12)?"
//Return: the user's answer
int generateFact(int num1, int num2)
{
	int answer{0};
	cout << "What is " << num1 << " * " << num2 << "? " ;
	cin >> answer;
	return answer;
}

//Desc:   displays messages when the user gets the correct answer
//Output: different kinds of messages so the user does not
//        always get the same message
void correctAnswer(int num)
{
	switch(num)
	{
		case 0: cout << "Very good!" << endl;
				break;
		case 1: cout << "Excellent!" << endl;
				break;
		case 2: cout << "Nice work!" << endl;
				break;
		case 3: cout << "Keep up the good work!" << endl;
				break;
	}
}

//Desc:   displays messages when the user enters an incorrect answer
//Output: various messages so the user does not
//        always receive the same messages
void incorrectAnswer(int num)
{
	switch(num)
	{
		case 0: cout << "No. Please try again" << endl;
				break;
		case 1: cout << "Wrong. Try once more." << endl;
				break;
		case 2: cout << "Don't give up!" << endl;
				break;
		case 3: cout << "No. Keep trying." << endl;
				break;
	}
}
