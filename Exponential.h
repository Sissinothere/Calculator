/*
* Exponential.h
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak
*/

#ifndef E_H_
#define E_H_


#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Exponential{
	double e_value;
	int coefficient, powerCount;
	string sValue;
	string answer;
	stringstream coefficientHandle;

public:

	Exponential(string sValue);
	string getAnswer();
	void setCoefficient();
	int getCoefficient();
	void clearBuffer();

	void Multiply(Exponential& in);
	void Divide(Exponential& in);
	void Add(Exponential& in);
	void Subtract(Exponential& in);
};


#endif /* E_H_ */

