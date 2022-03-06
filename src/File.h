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
	File(const int&, const int&, const int&, const int&, unsigned char*);
	/**
	 * Destructor
	 */
	virtual ~File();
	/**
	 * Print for debugging purposes.
	 * Parameters: the base of the numbers (the default is binary)
	 * Return: a string of the image contents
	 */
	const string print(const int&);
	/**
	 * Paint the ASCII art in a file.
	 * Parameters: the name of the file to be created or overwritten.
	 * Return: a return-code: 0 for success
	 */
	//const int paint(const string&);


private:
	int inHeight, inWidth, inMaximum, inLength, inType;
	unsigned char* puchData;
};

#endif /* FILE_H_ */
