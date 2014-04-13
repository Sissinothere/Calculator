/*
* Pi.cpp
*
*  Created on: Apr 11, 2014
*  Author: Abel Mak

*/

#include "Exponential.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Pi constructor accepts string parameter
Exponential::Exponential(string sValue)
{
	this->sValue = sValue; //String input stored
	this->e_value = 2.72;
	this->setCoefficient(); //Sets coefficient value to int
	this->powerCount = 1;
}


void Exponential::setCoefficient()
{
	if (!atoi(this->sValue.c_str()))
	{
		this->coefficient = 1;
	}
	this->coefficient = atoi(this->sValue.c_str());
}

int Exponential::getCoefficient()
{
	return this->coefficient;
}

string Exponential::getAnswer()
{
	return answer;
}

//clears stringstream buffer
void Exponential::clearBuffer()
{
	this->coefficientHandle.str("");
	this->coefficientHandle.clear();
}

//Accepts a Pi object and performs multiplication
void Exponential::Multiply(Exponential& in)
{
	this->clearBuffer();

	int coefficientMultiplication = (this->getCoefficient() * in.getCoefficient());
	//this->powerCount += 1;
	//in.powerCount += 1;

	coefficientHandle << coefficientMultiplication;
	string CoefConvert = coefficientHandle.str();

	//coefficientHandle.str("");
	//coefficientHandle.clear();

	//coefficientHandle << this->powerCount;
	//string powerConvert = coefficientHandle.str();

	//answer = CoefConvert + "pi^" + powerConvert;
	answer = CoefConvert + "e^2";
}

//Accepts a Pi object and performs division
void Exponential::Divide(Exponential& in)
{
	this->clearBuffer();

	int coefficientDivision = (this->getCoefficient() / in.getCoefficient());
	if (coefficientDivision == 1)
	{
		answer = "1";
	}

	else if (coefficientDivision % 2 == 0)
	{
		coefficientHandle << coefficientDivision;
		string convert = coefficientHandle.str();
		answer = convert;
	}
	else
	{
		coefficientHandle << this->getCoefficient();
		string thisCoef = coefficientHandle.str();

		coefficientHandle.str("");
		coefficientHandle.clear();

		coefficientHandle << in.getCoefficient();
		string inCoef = coefficientHandle.str();

		answer = "(" + thisCoef + "/" + inCoef + ")" + "e";
	}
}

//Accepts a Pi object and performs addition
void Exponential::Add(Exponential& in)
{
	this->clearBuffer();

	int coefficientAddition = this->getCoefficient() + in.getCoefficient();
	if (coefficientAddition == 0)
	{
		answer = "0";
	}
	coefficientHandle << coefficientAddition;
	string convert = coefficientHandle.str();
	answer = convert + "pi";
}

//Accepts a Pi object and performs subtraction
void Exponential::Subtract(Exponential& in)
{
	this->clearBuffer();

	int coefficientSubtraction = this->getCoefficient() - in.getCoefficient();
	if (coefficientSubtraction == 0)
	{
		answer = "0";
	}
	coefficientHandle << coefficientSubtraction;
	string convert = coefficientHandle.str();
	answer = convert + "e";
}

