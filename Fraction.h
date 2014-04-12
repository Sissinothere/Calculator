<<<<<<< HEAD
/* 
=======
/*
>>>>>>> FETCH_HEAD
 * File:   Fraction.h
 * Author: VinayakSundar
 *
 * Created on April 11, 2014, 7:59 PM
 */

#ifndef FRACTION_H
<<<<<<< HEAD
#define	FRACTION_H
=======
#define FRACTION_H
>>>>>>> FETCH_HEAD

using namespace std;

class Fraction{

private:
    int num1;
    int den1;
<<<<<<< HEAD
    
=======

>>>>>>> FETCH_HEAD
    int lcd;
    int gcd;
    int reduced_num;
    int reduced_den;
    int new_num1;
    int new_num2;
    int a;
<<<<<<< HEAD
   
    int new_fraction;
    int final_num;
    int final_den;
    
    int iValue;
    string sValue;
    string answer;
    
public:
    
    Fraction(string sValue);
    
=======

    int new_fraction;
    int final_num;
    int final_den;

    int iValue;
    string sValue;
    string answer;

public:

    Fraction(string sValue);

>>>>>>> FETCH_HEAD
    int getFraction();
    int getNumerator();
    int getDenominator();
    string getAnswer();
    void Reduction(Fraction& frac);
<<<<<<< HEAD
    bool canSimplifytoInteger(Fraction& frac);
=======
>>>>>>> FETCH_HEAD
    void Addition(Fraction& frac);
    void Subtraction(Fraction& frac);
    void Multiplication(Fraction& frac);
    void Division(Fraction& frac);



<<<<<<< HEAD
#endif	/* FRACTION_H */

};
=======
#endif  /* FRACTION_H */

};
>>>>>>> FETCH_HEAD
