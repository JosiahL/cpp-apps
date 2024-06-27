//Josiah Lovin
/* Recursion.cpp: Program displays what is returned
   from the recursive function. */
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long); //function prototype

int main()
{
	//calculate the factorials of 0 through 10
	for(unsigned int counter{0}; counter <= 10; ++counter)
	{
		cout << counter << "! =" << endl;
		cout << factorial(counter) << "\n\n";
	}
}

//recursive definition of function factorial
unsigned long factorial(unsigned long number)
{
	//test for base case
	if(number <= 1)
	{
		cout << "\treturns 1" << endl;
		return 1;
	}
	//recursion step
	else
	{
		cout << "\treturns " << number << " * " << number - 1 << "!" << endl;
		return number * factorial(number - 1);
	}
}