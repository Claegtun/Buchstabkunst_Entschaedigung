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
File::File(const int& inTypeArg = 5, const int& inHeightArg = 0, const int& inWidthArg = 0,
		const int& inMaximumArg = 1, char* pchBuffer = NULL)
{
	inType = inTypeArg;
	inHeight = inHeightArg;
	inWidth = inWidthArg;
	inMaximum = inMaximumArg;
	inLength = inHeight*inWidth;
	pchData = pchBuffer;
}

/**
 * Destructor
 */
File::~File()
{

}

/**
 * Print
 * Parameters:
 * Return: a string of the image contents
 */
const string File::print()
{
	string str = "";

	for (int i = 0; i < inLength; i++)
	{
		for (int j = 0; j < 8; j++)
			str += ((pchData[i] >> j) & 1) == 1 ? "1" : "0";

		str += " ";
	}

	return str;
}

