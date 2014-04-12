/*
 * File:   Fraction.h
 * Author: VinayakSundar
 *
 * Created on April 11, 2014, 7:59 PM
 */

#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class Fraction{

private:
    int num1;
    int den1;

    int lcd;
    int gcd;
    int reduced_num;
    int reduced_den;
    int new_num1;
    int new_num2;
    int a;

    int new_fraction;
    int final_num;
    int final_den;

    int iValue;
    string sValue;
    string answer;

public:

    Fraction(string sValue);

    int getFraction();
    int getNumerator();
    int getDenominator();
    string getAnswer();
    void Reduction(Fraction& frac);
    void Addition(Fraction& frac);
    void Subtraction(Fraction& frac);
    void Multiplication(Fraction& frac);
    void Division(Fraction& frac);



#endif  /* FRACTION_H */

};
