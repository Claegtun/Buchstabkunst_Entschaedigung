//============================================================================
// Name        : Buchstabkunst_Verbesserung.cpp
// Author      : Claegtun
// Version     :
// Copyright   :
// Description : A simple program to make ASCII art from a .PNG file
//============================================================================

#include <iostream> //cout
#include <fstream> //file IO
using namespace std;

int main() {
	cout << "Begin." << endl;

	//Open the input file.
	ifstream smInput("input.png");
	if (!smInput.is_open())
	{
		cout << "File could not be opened." << endl;
		return 1;
	}


	cout << "End." << endl;
	return 0;
}
