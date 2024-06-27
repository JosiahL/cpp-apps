//Josiah Lovin
/* Mystery.cpp: Program prompts the user for two
   integers. It then outputs the product of the integers. */
   
#include <iostream>
using namespace std;

//function prototype
int mystery(int, int);

//function main begins program execution
int main()
{
	cout << "Enter two integers: ";
	int x{0};
	int y{0};
	cin >> x >> y;
	cout << "The result is " << mystery(x, y) << endl;
}

//funciton mystery returns a * b
int mystery(int a, int b)
{
	//one base case
	if(b == 0)
		return 0;
	//second base case
	else if(b == 1)
		return a;
	//helper function
	else if(b < 0)
		return mystery(a * -1, b * -1);
	//recursion step
	else
		return a + mystery(a, b - 1);
}