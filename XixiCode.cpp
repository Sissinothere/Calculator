
//============================================================================
// Name        : Calculator.cpp
// Author      : Xixi Ruan
// Version     :
// Copyright   : Your copyright notice
// Description : Calculator in C++, Ansi-style
//============================================================================
//
//#include "Calculator1.cpp"
//#include "Simplify.cpp"



//==================================
#include "NobracketString.h"
#include "Logs.h"
#include "StringReader.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void menu(){
	cout<<"---------------------------------------------------------"<<endl;
	cout<< "Welcome to Number Cacluator System."<<endl;
	cout<< "Please enter your choice: " <<endl;
	cout<< "N.	Compute a new function." <<endl;
	cout<< "P.	Review previous function and answers." <<endl;
	// only one or multiple function?
	cout<< "H.	Help"<<endl;
	cout<< "Q.	Quit"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
//	cout<<"NOTE: "<<endl;
//	cout<<"I only figure out how to calculate Log class, "<<endl;
//	cout<<"because I don't have the other number type class in hand that I can test."<<endl;
//	cout<<"not even integer, I will create a integer class later then I do something like"<<endl;
//	cout<<"3+5*2"<<endl;
//
//	cout<<"but you can enter a complex express like: "<<endl;
//	cout<<"log_3:4-3*log3_5+log_3:5,"<<endl;
//	cout<<"log_3:4-3*log3_5+log_3:5,"<<endl;
//	cout<<"log_3:5+3/2+log_3:10"<<endl;
//	cout<<"do not enter (), it will not do the calculation"<<endl;
	cout<<endl;
}
void dropSpace(string str){
	int begin = 0;
	begin = str.find(" ",begin);//find the first position in the string
	while(begin!=-1){
		str.replace(begin,1,"");//drop the space
		begin = str.find(" ",begin);
	}
		StringReader *sr = new StringReader(str);
			sr->Inject();
			sr->Parenthesis();

}
void getFunction(){

	string function;
	cout<< "Please enter function: ";
	//cin>>function;
	getline(cin,function);//this function need to link to the class stringreader.

	dropSpace(function);
//	StringReader *sr = new StringReader(function);
//		sr->Inject();
//		sr->Parenthesis();

//		cout<<"============================================="<<endl;
//			cout<<"the answer is:"<<endl;
}

void help(){
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"This claculator is design to calculate simple and complicate mathmatics calculation."<<endl;
	cout<<"Operator specifications: "<<endl;
	cout<< "	< 'x to the power of y' == x^y >" << endl;
	cout<< "	< 'the square root of x' == sqrt:x >" << endl;
	cout<< "	< 'the nth root of x' == nrt:x, where 'n' is replaced by a number. >" << endl;
	cout<<'\t'<<"	Note: This could always just be done through x^(1/y)"<<endl;
	cout<< "	<'log base b of x' == log_b:x >" << endl;
	cout<<endl;
	cout<<"Tips: "<<endl;
	cout<<'\t'<<"* Please enter the entire function."<<endl;
	cout<<'\t'<<"* Do not enter '=' at the end of the function."<<endl;
	cout<<'\t'<<"* Can add parameters in the function."<<endl;
	cout<<'\t'<<"* Enter 'ans' to use the value from the last calculation."<<endl;
	cout<<"------------------------------------------------------------"<<endl;

}
int main(){
	string temp;
	char choice;
	do{
		menu();
		getline(cin,temp);
		choice= temp[0];
		switch(choice){
			case 'N':
			case 'n': 	getFunction();
						break;
			case 'P':
			case 'p': 	cout<<"get answer from relenvant class"<<endl;
						break;
			case 'H':
			case 'h':	help();
						break;
			case 'Q':
			case 'q':   cout<<"Thank you for using Number Calculator System. Bye~ "<<endl;
						break;
			default: 	cout<<"You entered a invalid choice " << choice <<" , plese enter a valid choice"<<endl;
			}

		}while(choice!='Q'&& choice!='q');// one is false, all false;
	return 0;
}


/*
 update(4/4): user can enter space to the formular.
 			  program will drop the space and pass the non-space string to the
 			  string reader.


*/


