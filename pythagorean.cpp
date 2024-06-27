//Josiah Lovin
/* pythagorean.cpp: program prints all pythagorean triples
   such that side1, side2, and the hypotenuse are < 500. */ 
#include<iostream>

using namespace std;

//function main begins program execution
int main()
{
	//output triples
	cout << "Pythagorean triples:" << endl;
	for(int i = 1; i < 501; ++i)
		for(int j = 1; j < 501; ++j)
			for(int k = 0; k < 501; ++k)
				if(i*i + j*j == k*k)
					cout << i << " " << j << " " << k << endl;
	return 0;
}