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
 * Read file
 * Parameters: the name of the file without extension
 * Return: a poitner to a file.
 */
File* readFile(const string& strFileName)
{
	//Open the input file.
	ifstream smInput(strFileName+".pgm");
	if (!smInput.is_open())
	{
		cout << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	//Find the length of the file.
	smInput.seekg(0, smInput.end);
	int iFileLength = smInput.tellg();
	smInput.seekg(0, smInput.beg);
	cout << iFileLength << endl;

	//Read the input file into a buffer.
	char* pchBuffer = new char[iFileLength];
	smInput.read(pchBuffer, iFileLength);
	smInput.close();

	//Check the header.
	if ((pchBuffer[0] != 'P') || (pchBuffer[1] != '5'))
	{
		cout << "Format of header is not valid." << endl;
		exit(EXIT_FAILURE);
	}

	//Read the header.
	string A3strHeader[3]; //Width, Height, Maximum
	int inIndex = 3; //The index in the buffer
	int inSafety = 0; //The safety count for skipping whitespaces
	//For each three arguments in the header, skip all whitespaces in between each and concatenate a string of the number.
	for (int i = 0; i < 3; i++)
	{
		while (((pchBuffer[inIndex] == ' ') || (pchBuffer[inIndex] == '\n')) && (inSafety++ < 100))
			inIndex++;
		while ((pchBuffer[inIndex] != ' ') && (pchBuffer[inIndex] != '\n'))
		{
			A3strHeader[i] += pchBuffer[inIndex++];
		}
		cout << A3strHeader[i] << endl;
	}

	//Make the File object.
	File* pFile;// = new File();

	return pFile;
}

/**
 * Run
 * Parameters:
 * Return:
 */
void run()
{
	File* pFile = readFile("bocklin-_2_");
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
