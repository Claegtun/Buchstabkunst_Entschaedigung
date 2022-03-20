/*
 * File.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: Claegtun
 */

#include <fstream> //file IO
#include "File.h"

/**
 * Constructor
 */
File::File()
{
	inType = 5;
	inWidth = 0;
	inHeight = 0;
	inMaximum = 0;
	inLength = inHeight*inWidth;
	puchData = NULL;
}
File::File(const unsigned int& inTypeArg = 5, const unsigned int& inWidthArg = 0,
		const unsigned int& inHeightArg = 0, const unsigned int& inMaximumArg = 1,
		unsigned char* puchDataArg = NULL)
{
	inType = inTypeArg;
	inWidth = inWidthArg;
	inHeight = inHeightArg;
	inMaximum = inMaximumArg;
	inLength = inHeight*inWidth;
	puchData = puchDataArg;
}

/**
 * Destructor
 */
File::~File()
{
	delete puchData;
}

/**
 * Read a PGM file
 * Parameters: the name of the PGM file without extension
 * Return: 	0 means fine;
 * 			1 means that the file could not be opened;
 * 			2 means that the format is invalid;
 */
const int File::readFile(const string& strFileName)
{
	//Open the input file.
	ifstream smInput(strFileName+".pgm");
	if (!smInput.is_open())
		return 1;

	//Find the length of the file.
	smInput.seekg(0, smInput.end);
	int inFileLength = smInput.tellg();
	smInput.seekg(0, smInput.beg);

	//Read the input file into a buffer.
	char* pchBuffer = new char[inFileLength];
	smInput.read(pchBuffer, inFileLength);
	smInput.close();

	//Check the header.
	if ((pchBuffer[0] != 'P') || (pchBuffer[1] != '5'))
		return 2;

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
	}

	//Read the data.
	int inDataLength = inFileLength - inHeaderLength;
	unsigned char* puchDataTemp = new unsigned char[inDataLength];
	for (int i = 0; i < inDataLength; i++)
		puchDataTemp[i] = pchBuffer[i+inHeaderLength];

	//Define the rest of the file's properties.
	inType = 5;
	inWidth = stoi(A3strHeader[0],nullptr,10);
	inHeight = stoi(A3strHeader[1],nullptr,10);
	inMaximum = stoi(A3strHeader[2],nullptr,10);
	puchData = puchDataTemp;

	return 0;
}

/**
 * Print for debugging purposes.
 * Parameters: the base of the numbers (the default is binary)
 * Return: a string of the image contents
 */
const string File::print(const unsigned int& inBase)
{
	string str = "";

	for (int i = 0; i < inLength; i++)
	{
		switch (inBase) {
			//Binary:
			default:
			case 2:
				for (int j = 0; j < 8; j++)
					str += ((puchData[i] >> j) & 1) == 1 ? "1" : "0";

				//str += " ";
				break;
			//Decimal:
			case 10:
				//Add leading zeros.
				if (puchData[i] < 10)
					str += "00";
				else if (puchData[i] < 100)
					str += "0";
				str += to_string((uint8_t)puchData[i]);

				str += " ";

				//Add a newline after each row.
				if (((i+1) % inWidth) == 0)
					str += "\n";
				break;
		}

	}

	return str;
}

/**
 * Paint the ASCII art into a string.
 * Parameters: the divisor, i.e. the reduction, in resolution.
 * Return: a string of the ASCII art
 */
const string File::paint(const unsigned int& divisor = 1)
{
	const char A10chShortSet[] = " .:-=+*#%@@";
	//const char A10chShortSet[] = "@@%#*+=-:. ";
	const unsigned int inShortSetLength = 11;
	string str;
	char ch;
	float fpValue;
	float fpAverage;

	//Each row:
	for (unsigned int i = 0; i < inHeight/divisor; i+=divisor)
	{
		//Each pixel:
		for (unsigned int j = 0; j < inWidth/divisor; j+=divisor)
		{
			//Compute the average.
			fpAverage = 0;
			for (unsigned int iPix = 0; iPix < divisor; iPix++)
			{
				for (unsigned int jPix = 0; jPix < divisor; jPix++)
				{
					//Compute the value of the pixel.
					fpValue = (float)(puchData[i*inWidth*divisor+j*divisor]
												*(inShortSetLength-1)
												/inMaximum);
					fpAverage += fpValue / ((float)(divisor*divisor));
				}
			}
			ch = A10chShortSet[(unsigned int)(fpAverage+0.5)];
			str += ch;
			str += ch;
		}

		str += "\n";
	}

	return str;
}

