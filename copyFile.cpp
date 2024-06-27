//Josiah Lovin
//copyFile.cpp
/*
    Desc:   Program takes the name of an input and output file
		    and copies the input file to the output file
    Input:  User enters the name of the input and output file
    Output: Prompts the user for file names and displays the results
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    //initialize variables
    string inFile{""};
    string inString{""};
    string outFile{""};
    int lines{0};
    int characters{0};
    //prompt user for file names
    cout << "Name of your input file: ";
    cin >> inFile;
    cout << "Name of your output file: ";
    cin >> outFile;
    //attempt to open file
    ifstream input{inFile};
    //exit if file does not exist
    if (!input)
    {
        cout << "Could not open " << inFile << endl;
        exit(1);
    }
    //attempt to open file
    ofstream output{outFile};
    //exit if file does not exist
    if (!output)
    {
        cout << "Could not open " << outFile << endl;
        exit(1);
    }
    //copy input to output
    while (getline(input,inString))
    {
        lines += 1;
        characters += inString.size();
        output << inString << endl;
    }
    //output results
    cout << "Your copy is done. \nThe file contained " << lines << " lines of data with " << characters << " characters of data." << endl;
    input.close();
    output.close();
    return 0;
}
