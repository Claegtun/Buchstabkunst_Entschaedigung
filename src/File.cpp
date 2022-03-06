/*
 * File.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: Claegtun
 */

#include "File.h"

/**
 * Constructor
 */
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
 * Parameters:
 * Return: a string of the ASCII art
 */
const string File::paint()
{
	const char A10chShortSet[] = " .:-=+*#%@@";
	//const char A10chShortSet[] = "@@%#*+=-:. ";
	const unsigned int inShortSetLength = 11;
	string str;
	char ch;

	//Each row:
	for (unsigned int i = 0; i < inHeight; i++)
	{
		for (unsigned int j = 0; j < inWidth; j++)
		{
			ch = A10chShortSet[(unsigned int)puchData[i*inWidth+j]*(inShortSetLength-1)/(inMaximum)];
			str += ch;
			str += ch;
		}

		str += "\n";
	}

	return str;
}

