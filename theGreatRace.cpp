//Josiah Lovin
//theGreatRace.cpp
/*
    Desc:   Program simulates a tortoise and hare race. The race is 70 units long.
            The program uses a random number to determine the spaces that the
            tortoise and hare move. The hare uses a high risk/high reward strategy
            during the race while the tortoise is slow and steady.
    Output: Messages showing the progress of the race.
            T and H are printed on the screen after each loop to
            represent the progress of the tortoise and the hare.
*/
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;
//define constants
const int RACE_END = 70;
//function prototypes
void moveTortoise(int* const);
void moveHare(int* const);
void printCurrentPositions(const int* const, const int* const);
//initialize global variables
default_random_engine engine{static_cast<unsigned int>(time(0))};
uniform_int_distribution<int> randomInt{1, 10};
int randInt{0};
//function main begins program execution
int main()
{
    //initialize variables
    int tortoise{1};
    int hare{1};
    int timer{0};
    //show user that the race is starting
    cout << "ON YOUR MARK, GET SET" << endl;
    cout << "BANG!!!!" << endl;
    cout << "AND THEY'RE OFF!!!!" << endl;
    //continually progress through the race until it is finished
    while (tortoise!=RACE_END && hare!=RACE_END)
    {
        moveTortoise(&tortoise);
        moveHare(&hare);
        printCurrentPositions(&tortoise, &hare);
        ++timer;
    }
    //display results
    if (tortoise>=hare)
        cout << "\nTORTOISE WINS!!! YAY!!!\n";
    else if(tortoise==hare)
        cout << "It's a tie!" << endl;
    else
        cout << "Hare wins. Yuck." << endl;
    //how long the race took
    cout << "TIME ELAPSED = " << timer << " seconds" << endl;
    return 0;
}
//Desc: Function determines how many spaces the tortoise moves.
//      The tortoise uses a low risk/low reward strategy
//Post: The tortoise's pointer is changed to its next location in the race
void moveTortoise(int*  const turtlePtr) {
	randInt = randomInt(engine);
	if(randInt<6)
		*turtlePtr += 3;
	else if(randInt==6 || randInt==7)
		*turtlePtr -= 6;
	else
		++*turtlePtr;
	if(*turtlePtr<1)
		*turtlePtr = 1;
	else if(*turtlePtr>70)
		*turtlePtr = 70;
	return;
}
//Desc: Function determines how many spaces the hare moves.
//      The hare uses a high risk/high reward strategy
//Post: The hare's pointer is changed to its next location in the race
void moveHare(int*  const rabbitPtr) {
	randInt = randomInt(engine);
	if(randInt>2 && randInt<5)
		*rabbitPtr += 9;
	else if(randInt==5)
		*rabbitPtr -= 12;
	else if(randInt>5 && randInt<9)
		++*rabbitPtr;
	else
		*rabbitPtr -= 2;
	if(*rabbitPtr<1)
		*rabbitPtr = 1;
	else if(*rabbitPtr>70)
		*rabbitPtr = 70;
	return;
}

//Desc:   displays the tortoise and hare's current location in the race
//Output: A 'T' and 'H' are printed on the screen to display the location
//        of the tortoise and the hare.
//        If they are in the same position, "OUCH!!" is printed to the screen.
void printCurrentPositions(const int*  const snapperPtr, const int* const bunnyPtr)
{
	for(int i=1; i<71; ++i)
	{
		if(*snapperPtr==i && *bunnyPtr==i)
			cout << "OUCH!!";
		else
		{
			if(*snapperPtr==i)
				cout << "T";
			else if(*bunnyPtr==i)
				cout << "H";
			else
				cout << " ";
		}
	}
	cout << endl;
	return;
}
