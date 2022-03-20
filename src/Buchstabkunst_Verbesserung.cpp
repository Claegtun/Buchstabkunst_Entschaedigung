//============================================================================
// Name        : Buchstabkunst_Verbesserung.cpp
// Author      : Claegtun
// Version     :
// Copyright   :
// Description : A simple program to make ASCII art from a .PGM file
//============================================================================

#include <iostream> //cout
#include <fstream> //file IO
#include <stdlib.h> //exit
#include <string> //string
#include <array> //array
#include "File.h" //File
using namespace std;

/**
 * Run
 * Parameters:
 * Return:
 */
void run()
{
	File* pFile = new File();
	pFile->readFile("bocklin-_2_");

	ofstream smRawText("raw.txt");
	smRawText << pFile->print(10);
	smRawText.close();

	ofstream smArtText("art.txt");
	smArtText << pFile->paint();
	smArtText.close();

	delete pFile;
	return;
}

/**
 * Main
 */
int main()
{
	cout << "Begin." << endl;

	run();

	cout << "End." << endl;
	return 0;
}
