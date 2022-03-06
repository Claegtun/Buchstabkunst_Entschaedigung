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
File::File(const int& inTypeArg = 5, const int& inWidthArg = 0, const int& inHeightArg = 0,
		const int& inMaximumArg = 1, unsigned char* puchDataArg = NULL)
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
const string File::print(const int& inBase)
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

				//str += " ";

				//Add a newline after each row.
				if (((i+1) % inWidth) == 0)
					str += "\n";
				break;
		}

	}

	return str;
}

/**
 * Paint the ASCII art in a file.
 * Parameters: the name of the file to be created or overwritten without the extension.
 * Return: a return-code: 0 for success
 */
/*const string File::paint(const string& strFileName)
{

	return 0;
}*/

