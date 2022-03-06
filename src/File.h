/*
 * File.h
 *
 *  Created on: 14 Feb 2022
 *      Author: Claegtun
 */

#ifndef FILE_H_
#define FILE_H_

#include <string> //string, to_string
using namespace std;

class File
{
public:
	/**
	 * Constructor
	 */
	File(const unsigned int&, const unsigned int&, const unsigned int&,
			const unsigned int&, unsigned char*);
	/**
	 * Destructor
	 */
	virtual ~File();
	/**
	 * Print for debugging purposes.
	 * Parameters: the base of the numbers (the default is binary)
	 * Return: a string of the image contents
	 */
	const string print(const unsigned int&);
	/**
	 * Paint the ASCII art into a string.
	 * Parameters:
	 * Return: a string of the ASCII art
	 */
	const string paint();


private:
	unsigned int inHeight, inWidth, inMaximum, inLength, inType;
	unsigned char* puchData;
};

#endif /* FILE_H_ */
