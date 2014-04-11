/*
 * Integer.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Administrator

	UPDATE (4/10):
 */

#include "Integers.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Integer constructor accepts string parameter
Integers::Integers(string sValue)
{
	this->sValue = sValue; //String input stored
	iValue = atoi(sValue.c_str()); //String input converted to Int
}


int Integers::getValue()
{
	return iValue;
}

//Accepts an Integer object and performs multiplication
string Integers::Multiply(Integers& in)
	{
	string result;
	//result = ((this->getValue)*(in.getValue())); 			//this line has error
	int numOne = this->getValue();
	int numTwo = in.getValue();
	//this->numb *= lg.getNumb();
	result = numOne * numTwo;
	return answer;//return a string with the contents of the stream
	}

//Accepts an Integer object and performs division
string Integers::Divide(Integers& in)
	{
	int numOne = this->getValue();
	int numTwo = in.getValue();

	if(numOne%numTwo == 0)
	{
		int result =  numOne/numTwo;

		return answer;//return a string with the contents of the stream
	}
	else
	{
		answer = "/" + numTwo; //add number to the stream
		//void answer; //return a string with the contents of the stream
	}
	}

//Accepts an Integer object and performs addition
void Integers::Add(Integers& in)
{

	int ans =  this->getValue() + in.getValue();
	cout<<"the integer add is "<<answer<<endl;
	//answer = result; //add number to the stream
	ostringstream convert;
	convert << ans;      // insert the textual representation of 'Number' in the characters in the stream
	answer = convert.str();
	//return answer; //return a string with the contents of the stream
	}

//Accepts an Integer object and performs subtraction
string Integers::Subtract(Integers& in)
	{
	int numOne = this->getValue();
	int numTwo = in.getValue();
	int result =  numOne - numTwo;
	answer = result; //add number to the stream
	return answer; //return a string with the contents of the stream
	}

//Returns current answer
string Integers::getAnswer()
{
	return answer;
}

