/*
 * File.h
 *
 *  Created on: 14 Feb 2022
 *      Author: Claegtun
 */

#ifndef FILE_H_
#define FILE_H_

#include <string> //string
using namespace std;

class File
{
public:
	/**
	 * Constructor
	 */
	File(const int&, const int&, const int&, const int&, char*);
	/**
	 * Destructor
	 */
	virtual ~File();
	/**
	 * Print
	 * Parameters:
	 * Return: a string of the image contents
	 */
	const string print();


private:
	int inHeight, inWidth, inMaximum, inLength, inType;
	char* pchData;
};

#endif /* FILE_H_ */
