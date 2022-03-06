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
 * Parameters: the name of the PGM file without extension
 * Return: a pointer to a file.
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
	int inFileLength = smInput.tellg();
	smInput.seekg(0, smInput.beg);
	cout << inFileLength << endl;

	//Read the input file into a buffer.
	char* pchBuffer = new char[inFileLength];
	smInput.read(pchBuffer, inFileLength);
	smInput.close();

	//Check the header.
	if ((pchBuffer[0] != 'P') || (pchBuffer[1] != '5'))
	{
		cout << "Format of header is not valid." << endl;
		exit(EXIT_FAILURE);
	}

	//Read the header.
	string A3strHeader[3]; //Width, Height, Maximum
	int inHeaderLength = 3; //The index in the buffer
	int inSafety = 0; //The safety count for skipping whitespaces
	//For each three arguments in the header, skip all whitespaces in between each and concatenate a string of the number.
	for (int i = 0; i < 3; i++)
	{
		while (((pchBuffer[inHeaderLength] == ' ') || (pchBuffer[inHeaderLength] == '\n')) && (inSafety++ < 100))
			inHeaderLength++;
		while ((pchBuffer[inHeaderLength] != ' ') && (pchBuffer[inHeaderLength] != '\n'))
			A3strHeader[i] += pchBuffer[inHeaderLength++];
		cout << A3strHeader[i] << endl;
	}

	//Read the data.
	int inDataLength = inFileLength - inHeaderLength;
	unsigned char* puchData = new unsigned char[inDataLength];
	for (int i = 0; i < inDataLength; i++)
		puchData[i] = pchBuffer[i+inHeaderLength];

	//Make the File object.
	File* pFile = new File(	5,
							stoi(A3strHeader[0],nullptr,10),
							stoi(A3strHeader[1],nullptr,10),
							stoi(A3strHeader[2],nullptr,10),
							puchData);

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
