#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <cmath>
#include <string>

#include "Fraction.h"

using namespace std;
<<<<<<< HEAD
//=============================================================================
//      Name: Vinayak Sundar                                                  
//      Date: April 10, 2014
//      Title: Fraction Operators
//      Class: COP3503
//      
//
//
//=============================================================================






Fraction::Fraction(string sValue)
{
    this->sValue = sValue; 
    iValue = atoi(sValue.c_str());
    
=======

Fraction::Fraction(string sValue)
{
    this->sValue = sValue;
    iValue = atoi(sValue.c_str());

>>>>>>> FETCH_HEAD
}

int Fraction::getFraction()
{
    return iValue;
<<<<<<< HEAD
    
=======

>>>>>>> FETCH_HEAD
}

int Fraction::getNumerator()
{
<<<<<<< HEAD
    return num1; 
    
=======
    return num1;

>>>>>>> FETCH_HEAD
}

int Fraction::getDenominator()
{
    return den1;
}


    void Fraction::Reduction(Fraction& frac)
    {
<<<<<<< HEAD
       
              
=======


>>>>>>> FETCH_HEAD
        for(int i=1;i<=num1&&i<=den1;i++){


                if(num1%i==0 && den1%i == 0 ){

                     gcd=i;

                }

        }
<<<<<<< HEAD
        
       
        
        lcd = ((num1) * (den1)) / gcd;
        
        //cout << "The Least Common Denominator is: "<< lcd << endl;

        //cout<<"Greatest Common Divison (GCD):"<<gcd<<endl;
        
       
        
        num1 = num1 / gcd;
        den1 = den1 / gcd;
        
        ostringstream convert;
        convert << num1 << "/" << den1;
	answer = convert.str();
        
    }
    
    bool Fraction::canSimplifytoInteger(Fraction& frac){
        for(int i=1;i<=num1&&i<=den1;i++){


                if(num1%i==0 && den1%i == 0 ){

                     gcd=i;

                }

        }
        
       
        
        lcd = ((num1) * (den1)) / gcd;
        
        //cout << "The Least Common Denominator is: "<< lcd << endl;

        //cout<<"Greatest Common Divison (GCD):"<<gcd<<endl;
        
       
        
        num1 = num1 / gcd;
        den1 = den1 / gcd;
        
        if(den1 == 1)
            answer = true;
        else
            answer = false;
    }

    void Fraction::Addition(Fraction& frac){
    
   
    
    if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }
    
    
=======



        lcd = ((num1) * (den1)) / gcd;

        //cout << "The Least Common Denominator is: "<< lcd << endl;

        //cout<<"Greatest Common Divison (GCD):"<<gcd<<endl;



        num1 = num1 / gcd;
        den1 = den1 / gcd;

        ostringstream convert;
        convert << num1 << "/" << den1;
        answer = convert.str();

    }

    void Fraction::Addition(Fraction& frac){



    if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;

    }


>>>>>>> FETCH_HEAD
        for(int i=1;i<=den1 && i<=frac.getDenominator();i++){


                if(den1%i == 0 && (frac.getDenominator())%i ==0){

                     gcd=i;

                }

        }
<<<<<<< HEAD
     
   
        
        lcd = ((den1) * (frac.getDenominator())) / gcd;
        
        //cout << "The Least Common Denominator is: "<< lcd << endl;
    
        
        
         a = lcd / den1;
         
        
        num1 = a * num1;
       
        
        
        
        new_fraction = (new_num1 + frac.getNumerator());
        
       
        
        if (new_fraction < lcd){
		for (int i = new_fraction; i >=0; i--){
			if (new_fraction%i ==0 && lcd%i==0){
				
=======



        lcd = ((den1) * (frac.getDenominator())) / gcd;

        //cout << "The Least Common Denominator is: "<< lcd << endl;



         a = lcd / den1;


        num1 = a * num1;




        new_fraction = (new_num1 + frac.getNumerator());



        if (new_fraction < lcd){
                for (int i = new_fraction; i >=0; i--){
                        if (new_fraction%i ==0 && lcd%i==0){

>>>>>>> FETCH_HEAD
                            ostringstream convert;
                            convert << "The answer is: " << new_fraction/i << "/" << lcd/i;
                            answer = convert.str();
                            //cout << "The answer is: " << new_fraction/i << "/" << lcd/i << endl;
<<<<<<< HEAD
				
			}
		}
	}
	if (new_fraction > lcd){
		for(int i = lcd; i >=0; i--){
			
=======

                        }
                }
        }
        if (new_fraction > lcd){
                for(int i = lcd; i >=0; i--){

>>>>>>> FETCH_HEAD
                            ostringstream convert;
                            convert <<"The answer is: "<< new_fraction/i << "/" << lcd/i;
                            answer = convert.str();
                    //cout <<"The answer is: "<< new_fraction/i << "/" << lcd/i << endl;
<<<<<<< HEAD
			
		}
	}
	if(new_fraction == lcd){
		
=======

                }
        }
        if(new_fraction == lcd){

>>>>>>> FETCH_HEAD
            ostringstream convert;
            convert << "The answer is: 1";
            answer = convert.str();
            //cout << "The answer is: 1";
<<<<<<< HEAD
		
	}

        
       
        
        
        //cout << reduced_num << "/" << reduced_den << endl;
        //cout << new_fraction <<"/"<<lcd<< endl;
        
   
    
    }
    
    
    
=======

        }





        //cout << reduced_num << "/" << reduced_den << endl;
        //cout << new_fraction <<"/"<<lcd<< endl;



    }



>>>>>>> FETCH_HEAD



  void Fraction::Subtraction(Fraction& frac){
<<<<<<< HEAD
  
    
     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }
    
    
=======


     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;

    }


>>>>>>> FETCH_HEAD
        for(int i=1;i<=den1;i++){


                if(den1%i==0){

                     gcd=i;

                }

        }
<<<<<<< HEAD
     
   
        
        lcd = ((num1) * (den1)) / gcd;
        
              
        //cout << "The Least Common Denominator is: "<< lcd << endl;
    
        
        
        a = lcd / den1;
        
        
        new_num1 = a * num1;
        
        
        
        new_fraction = (new_num1 - new_num2);
        
=======



        lcd = ((num1) * (den1)) / gcd;


        //cout << "The Least Common Denominator is: "<< lcd << endl;



        a = lcd / den1;


        new_num1 = a * num1;



        new_fraction = (new_num1 - new_num2);

>>>>>>> FETCH_HEAD
        if(new_fraction == 0){
            ostringstream convert;
            convert << "The answer is: 0";
            answer = convert.str();
            //cout << "The answer is: 0" << endl;
<<<<<<< HEAD
            
        }
        
       if (new_fraction < lcd){
		for (int i = new_fraction; i >=0; i--){
			if (new_fraction%i ==0 && lcd%i==0){
			 ostringstream convert;
                        convert << "The answer is: "<< new_fraction/i << "/" << lcd/i;
                        answer = convert.str();	
                        //cout << "The answer is: "<< new_fraction/i << "/" << lcd/i;
				
			}
		}
	}
	if (new_fraction > lcd){
		for(int i = lcd; i >=0; i--){
			//cout << "The answer is: " << new_fraction/i << "/" << lcd/i;
			ostringstream convert;
                        convert << "The answer is: " << new_fraction/i << "/" << lcd/i;
                        answer = convert.str();
		}
	}
	if(new_fraction == lcd){
		//cout << "The answer is: 1";
		ostringstream convert;
                convert << "The answer is: 1";
                answer = convert.str();
	}
        
       
        
=======

        }

       if (new_fraction < lcd){
                for (int i = new_fraction; i >=0; i--){
                        if (new_fraction%i ==0 && lcd%i==0){
                         ostringstream convert;
                        convert << "The answer is: "<< new_fraction/i << "/" << lcd/i;
                        answer = convert.str();
                        //cout << "The answer is: "<< new_fraction/i << "/" << lcd/i;

                        }
                }
        }
        if (new_fraction > lcd){
                for(int i = lcd; i >=0; i--){
                        //cout << "The answer is: " << new_fraction/i << "/" << lcd/i;
                        ostringstream convert;
                        convert << "The answer is: " << new_fraction/i << "/" << lcd/i;
                        answer = convert.str();
                }
        }
        if(new_fraction == lcd){
                //cout << "The answer is: 1";
                ostringstream convert;
                convert << "The answer is: 1";
                answer = convert.str();
        }



>>>>>>> FETCH_HEAD
        else{
            ostringstream convert;
            convert << "The answer is: " << new_fraction << "/" << lcd;
            answer = convert.str();
            //cout << "The answer is: " << new_fraction << "/" << lcd << endl;
        }
<<<<<<< HEAD
            
        
        
    }
        
       
    



 void Fraction::Multiplication(Fraction& frac){
    
     
    
     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }
    
    //Multiplication Error!!!! Can someone please solve this??
    final_num = num1 * frac.getNumerator();
    final_den = den1 * frac.getDenominator();
    
       if (final_num < final_den){
		for (int i = final_num; i >=0; i--){
			if (final_num%i ==0 && final_den%i==0){
                                ostringstream convert;
                                convert << "The answer is: " << final_num/i << "/" << final_den/i;
                                answer = convert.str();
				//cout << "The answer is: " << final_num/i << "/" << final_den/i << endl;
				
			}
		}
	}
	if (final_num > final_den){
		for(int i = final_den; i >=0; i--){
                                ostringstream convert;
                                convert <<"The answer is: "<< final_num/i << "/" << final_den/i;
                                answer = convert.str();
			//cout <<"The answer is: "<< final_num/i << "/" << final_den/i << endl;
			
		}
	}
	if(final_num == final_den){
=======



    }


 void Fraction::Multiplication(Fraction& frac){



     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;

    }

    //Multiplication Error!!!! Can someone please solve this??
    final_num = num1 * frac.getNumerator();
    final_den = den1 * frac.getDenominator();

       if (final_num < final_den){
                for (int i = final_num; i >=0; i--){
                        if (final_num%i ==0 && final_den%i==0){
                                ostringstream convert;
                                convert << "The answer is: " << final_num/i << "/" << final_den/i;
                                answer = convert.str();
                                //cout << "The answer is: " << final_num/i << "/" << final_den/i << endl;

                        }
                }
        }
        if (final_num > final_den){
                for(int i = final_den; i >=0; i--){
                                ostringstream convert;
                                convert <<"The answer is: "<< final_num/i << "/" << final_den/i;
                                answer = convert.str();
                        //cout <<"The answer is: "<< final_num/i << "/" << final_den/i << endl;

                }
        }
        if(final_num == final_den){
>>>>>>> FETCH_HEAD
            ostringstream convert;
            convert << "The answer is: 1";
            answer = convert.str();
                //cout << "The answer is: 1";
<<<<<<< HEAD
		
	}

    
    
    //cout << final_num <<"/"<< final_den << endl;
    
        }


    

void Fraction::Division(Fraction& frac){
    
    
    
     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }
    
     // Division Error!!! Can someone please solve this
    final_num = num1 * frac.getDenominator();
    final_den = den1 * frac.getNumerator();
    
    if (final_num < final_den){
		for (int i = final_num; i >=0; i--){
			if (final_num%i ==0 && final_den%i==0){
                            ostringstream convert;
                            convert << "The answer is: " << final_num/i << "/" << final_den/i;
                            answer = convert.str();
				//cout << "The answer is: " << final_num/i << "/" << final_den/i << endl;
				
			}
		}
	}
	if (final_num > final_den){
		for(int i = final_den; i >=0; i--){
                    ostringstream convert;
                    convert <<"The answer is: "<< final_num/i << "/" << final_den/i;
                    answer = convert.str();
			//cout <<"The answer is: "<< final_num/i << "/" << final_den/i << endl;
			
		}
	}
	if(final_num == final_den){
                    ostringstream convert;
                    convert << "The answer is: 1";
                    answer = convert.str();
		//cout << "The answer is: 1";
		
	}
    
=======
        }
 }


void Fraction::Division(Fraction& frac){

     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;

    }

     // Division Error!!! Can someone please solve this
    final_num = num1 * frac.getDenominator();
    final_den = den1 * frac.getNumerator();

    if (final_num < final_den){
                for (int i = final_num; i >=0; i--){
                        if (final_num%i ==0 && final_den%i==0){
                            ostringstream convert;
                            convert << "The answer is: " << final_num/i << "/" << final_den/i;
                            answer = convert.str();
                                //cout << "The answer is: " << final_num/i << "/" << final_den/i << endl;

                        }
                }
        }
        if (final_num > final_den){
                for(int i = final_den; i >=0; i--){
                    ostringstream convert;
                    convert <<"The answer is: "<< final_num/i << "/" << final_den/i;
                    answer = convert.str();
                        //cout <<"The answer is: "<< final_num/i << "/" << final_den/i << endl;

                }
        }
        if(final_num == final_den){
                    ostringstream convert;
                    convert << "The answer is: 1";
                    answer = convert.str();
                //cout << "The answer is: 1";

        }

>>>>>>> FETCH_HEAD
        else{
            ostringstream convert;
            convert << final_num << "/" << final_den;
            answer = convert.str();
            //cout << final_num << "/" << final_den << endl;
        }

<<<<<<< HEAD
    
    
    
=======



>>>>>>> FETCH_HEAD
    }

//Returns the answer as a string
string Fraction::getAnswer()
{
    return answer;
<<<<<<< HEAD
    
}

    
    



int main()
{
    
}



=======
}
>>>>>>> FETCH_HEAD
