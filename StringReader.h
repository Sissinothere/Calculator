/*
 * StringReader.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Administrator
 */

#ifndef STRINGREADER_H_
#define STRINGREADER_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringReader {
	string input;

public:

	void Inject();
	string Parenthesis();
	bool isParen();
	StringReader(string input);
	//StringReader();
	//virtual ~StringReader();
};

#endif /* STRINGREADER_H_ */
