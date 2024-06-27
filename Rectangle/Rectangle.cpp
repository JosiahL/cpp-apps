//Josiah Lovin
//Rectangle.cpp
/*
    Desc:   Program takes the length and width of a rectangle and
            outputs the area and perimeter of the rectangle
    Input:  User inputs the length and width of the rectangle
            User enters a length and width of 0 to exit the program
    Output: Prompts the user for input and output
            Displays the area and perimeter of the rectangle
    Pre:    Includes the Rectangle.h class
*/
#include <iostream>
#include "Rectangle.h"
using namespace std;
//function main begins program execution
int main()
{
    //initialize variables
	int length{1};
	int width{1};
	Rectangle rectangle1{1, 1};
	//welcome the user
	cout << "Hello! Welcome to the Rectangle program. Please enter the " << endl;
	cout << "dimensions for a rectangle when prompted. Valid size ranges " << endl;
	cout << "from 1 to 20 for length and width. The program will end when " << endl;
	cout << "you enter 0 for both the length and width." << endl;
	//continue to prompt user for input until sentinel is reached
	while(length!=0 || width!=0)
	{
        //prompt user for input
        cout << "Enter the length of your rectangle: ";
        cin >> length;
        cout << "Enter the width of your rectangle: ";
        cin >> width;
        //check for valid sizes
        while(length<0 || length>20 || width<0 || width>20 || (length==0 && width!=0) || (width==0 && length!=0))
        {
            cout << "Please enter valid dimensions." << endl;
            cout << "Enter the length of your rectangle: ";
            cin >> length;
            cout << "Enter the width of your rectangle: ";
            cin >> width;
        }
        //display results of length and width if they are not both 0
        //only have to check length because we know if length is 0
        //then width must be 0 after the validation above
        if(length!=0)
        {
            rectangle1.setLength(length);
            rectangle1.setWidth(width);
            cout << "Your " << rectangle1.getLength() << " x " << rectangle1.getWidth()
            << " rectangle has an area = " << rectangle1.area() << " and a perimeter = "
            << rectangle1.perimeter() << endl;
        }
	}
	//thank user for running program
	cout << "Thank you for using the Rectangle program. Goodbye!";
	return 0;
}
