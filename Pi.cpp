/*
* Pi.cpp
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak

*/

#include "Pi.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Pi constructor accepts string parameter
Pi::Pi(string sValue)
{
	this->sValue = sValue; //String input stored
	this->Pi_value = 3.14;
}


string Pi::getAnswer()
{
	return answer;
}

//Accepts an Pi object and performs multiplication
void Pi::Multiply(Pi& in)
{
	answer = "pi^2";
}

//Accepts an Pi object and performs division
void Pi::Divide(Pi& in)
{
	answer = "1";
}

//Accepts an Pi object and performs addition
void Pi::Add(Pi& in)
{
	answer = "2*pi";
}

//Accepts an Pi object and performs subtraction
void Pi::Subtract(Pi& in)
{
	answer = "0";
}

