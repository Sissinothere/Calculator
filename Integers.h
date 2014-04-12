/*
 * Integers.h
 *
 *  Created on: Apr 6, 2014
 *      Author: Administrator
 */

#ifndef INTEGERS_H_
#define INTEGERS_H_

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <cmath>
#include <string>



using namespace std;


class Fraction{

private:
   // string input;
    int num1;
    int den1;
    int num2;

    int lcd;
    int gcd;
    int reduced_num;
    int reduced_den;
    int new_num1;
    int new_num2;
    int a;
    int b;

    int new_fraction;
    int final_num;
    int final_den;


    int iValue;
    string sValue1;
    //string sValue2;
    string strnum1;
    string strden1;
    string answer;
    bool result;

public:

    Fraction(string sValue);

    int getFraction();
    int getNumerator();
    int getDenominator();
    string getAnswer();
    void Reduction();
    bool canSimplifytoInteger();
    void Addition(Fraction& fracB);
    void Subtraction(Fraction& frac);
    void Multiplication(Fraction& frac);
    void Division(Fraction& frac);




};

#endif /* INTEGERS_H_ */

