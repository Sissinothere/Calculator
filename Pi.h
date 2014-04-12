/*
* Pi.h
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#ifndef PI_H_
#define PI_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Pi{
	double Pi_value;
	string sValue;
	string answer;

public:

	Pi(string sValue);
	string getAnswer();

	void Multiply(Pi& in);
	void Divide(Pi& in);
	void Add(Pi& in);
	void Subtract(Pi& in);
};


#endif /* PI_H_ */

