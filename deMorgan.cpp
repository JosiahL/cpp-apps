//Josiah Lovin
/* deMorgan.cpp: program tests De Morgan's laws
   for 4 different arguments. */
#include<iostream>

using namespace std;

//fuction main begins program execution
int main()
{
	//Test ((!x < 5) && !(y >= 7)) and !(x < 5 || y >= 7)
	int x{5};
	int y{10};
	cout << "\nTesting ((!x < 5) && !(y >= 7)) and !(x < 5 || y >= 7):" << endl;
	cout << "x = 5, y = 10" <<  endl;
	cout << boolalpha << "(!(x < 5) && !(y >= 7)): " << (!(x < 5) && !(y >= 7)) << endl;
	cout << boolalpha << "!(x < 5 || y >= 7): " << !(x < 5 || y >= 7) << endl;
	cout << "x = 9, y = 3" << endl;
	x = 9;
	y = 3;
	cout << boolalpha << "(!(x < 5) && !(y >= 7)): " << (!(x < 5) && !(y >= 7)) << endl;
	cout << boolalpha << "!(x < 5 || y >= 7): " << !(x < 5 || y >= 7) << endl;
	cout << "x = 3, y = 7" << endl;
	x = 3;
	y = 7;
	cout << boolalpha << "(!(x < 5) && !(y >= 7)): " << (!(x < 5) && !(y >= 7)) << endl;
	cout << boolalpha << "!(x < 5 || y >= 7): " << !(x < 5 || y >= 7) << endl;
	cout << "x = 2, y = 6" << endl;
	x = 2;
	y = 6;
	cout << boolalpha << "(!(x < 5) && !(y >= 7)): " << (!(x < 5) && !(y >= 7)) << endl;
	cout << boolalpha << "!(x < 5 || y >= 7): " << !(x < 5 || y >= 7) << endl;
	
	//Test (!(a == b) || !(g != 5)) and !(a == b && g != 5)
	int a{5};
	int b{5};
	int g{10};
	cout << "\nTesting (!(a == b) || !(g != 5)) and !(a == b && g != 5):" << endl;
	cout << "a = 5, b = 5, g = 10" <<  endl;
	cout << boolalpha << "(!(a == b) || !(g != 5)): " << (!(a == b) || !(g != 5)) << endl;
	cout << boolalpha << "!(a == b && g != 5): " << !(a == b && g != 5) << endl;
	cout << "a = 7, b = 11, g = 5" << endl;
	a = 7;
	b = 11;
	g = 5;
	cout << boolalpha << "(!(a == b) || !(g != 5)): " << (!(a == b) || !(g != 5)) << endl;
	cout << boolalpha << "!(a == b && g != 5): " << !(a == b && g != 5) << endl;
	cout << "a = 8, b = 8, g = 5" << endl;
	a = 8;
	b = 8;
	g = 5;
	cout << boolalpha << "(!(a == b) || !(g != 5)): " << (!(a == b) || !(g != 5)) << endl;
	cout << boolalpha << "!(a == b && g != 5): " << !(a == b && g != 5) << endl;
	cout << "a = 4, b = 1, g = 2" << endl;
	a = 4;
	b = 1;
	g = 2;
	cout << boolalpha << "(!(a == b) || !(g != 5)): " << (!(a == b) || !(g != 5)) << endl;
	cout << boolalpha << "!(a == b && g != 5): " << !(a == b && g != 5) << endl;
	
	//Test !((x <= 8) && (y > 4)) and (!(x <= 8) || !(y > 4))
	 x = 8;
	 y = 5;
	cout << "\nTesting !((x <= 8) && (y > 4)) and (!(x <= 8) || !(y > 4)):" << endl;
	cout << "x = 8, y = 5" <<  endl;
	cout << boolalpha << "!((x <= 8) && (y > 4)): " << !((x <= 8) && (y > 4)) << endl;
	cout << boolalpha << "(!(x <= 8) || !(y > 4)): " << (!(x <= 8) || !(y > 4)) << endl;
	cout << "x = 9, y = 4" << endl;
	x = 9;
	y = 4;
	cout << boolalpha << "!((x <= 8) && (y > 4)): " << !((x <= 8) && (y > 4)) << endl;
	cout << boolalpha << "(!(x <= 8) || !(y > 4)): " << (!(x <= 8) || !(y > 4)) << endl;
	cout << "x = 2, y = 1" << endl;
	x = 2;
	y = 1;
	cout << boolalpha << "!((x <= 8) && (y > 4)): " << !((x <= 8) && (y > 4)) << endl;
	cout << boolalpha << "(!(x <= 8) || !(y > 4)): " << (!(x <= 8) || !(y > 4)) << endl;
	cout << "x = 10, y = 6" << endl;
	x = 10;
	y = 6;
	cout << boolalpha << "!((x <= 8) && (y > 4)): " << !((x <= 8) && (y > 4)) << endl;
	cout << boolalpha << "(!(x <= 8) || !(y > 4)): " << (!(x <= 8) || !(y > 4)) << endl;
	
	//Test !((i > 4) || (j <= 6)) and (!(i > 4) && !(j <= 6))
	int i{5};
	int j{6};
	cout << "\nTesting !((i > 4) || (j <= 6)) and (!(i > 4) && !(j <= 6)):" << endl;
	cout << "i = 5, j = 10" <<  endl;
	cout << boolalpha << "!((i > 4) || (j <= 6)): " << !((i > 4) || (j <= 6)) << endl;
	cout << boolalpha << "(!(i > 4) && !(j <= 6)): " << (!(i > 4) && !(j <= 6)) << endl;
	cout << "i = 4, y = 7" << endl;
	i = 4;
	j = 7;
	cout << boolalpha << "!((i > 4) || (j <= 6)): " << !((i > 4) || (j <= 6)) << endl;
	cout << boolalpha << "(!(i > 4) && !(j <= 6)): " << (!(i > 4) && !(j <= 6)) << endl;
	cout << "i = 8, j = 9" << endl;
	i = 8;
	j = 9;
	cout << boolalpha << "!((i > 4) || (j <= 6)): " << !((i > 4) || (j <= 6)) << endl;
	cout << boolalpha << "(!(i > 4) && !(j <= 6)): " << (!(i > 4) && !(j <= 6)) << endl;
	cout << "x = 3, y = 2" << endl;
	i = 3;
	j = 2;
	cout << boolalpha << "!((i > 4) || (j <= 6)): " << !((i > 4) || (j <= 6)) << endl;
	cout << boolalpha << "(!(i > 4) && !(j <= 6)): " << (!(i > 4) && !(j <= 6)) << endl;
	
	return 0;
}