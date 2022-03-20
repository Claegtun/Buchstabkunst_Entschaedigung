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
	File();
	File(const unsigned int&, const unsigned int&, const unsigned int&,
			const unsigned int&, unsigned char*);
	/**
	 * Destructor
	 */
	virtual ~File();
	/**
	 * Read a PGM file
	 * Parameters: the name of the PGM file without extension
	 * Return: 	0 means fine;
	 * 			1 means that the file could not be opened;
	 * 			2 means that the format is invalid;
	 */
	const int readFile(const string& strFileName);
	/**
	 * Print for debugging purposes.
	 * Parameters: the base of the numbers (the default is binary)
	 * Return: a string of the image contents
	 */
	const string print(const unsigned int&);
	/**
	 * Paint the ASCII art into a string.
	 * Parameters: the divisor, i.e. the reduction, in resolution.
	 * Return: a string of the ASCII art
	 */
	const string paint(const unsigned int&);


private:
	unsigned int inHeight, inWidth, inMaximum, inLength, inType;
	unsigned char* puchData;
};

#endif /* FILE_H_ */
