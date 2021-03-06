
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
//abel was here


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
	cout<<"Please enter your choice: "<<endl;
	cout<<endl;
}
string dropSpace(string str){
	int begin = 0;
	begin = str.find(" ",begin);//find the first position in the string
	while(begin!=-1){
		str.replace(begin,1,"");//drop the space
		begin = str.find(" ",begin);
	}
	stringstream ss;
	ss << '(';
	ss<<str;
	ss<<')';

	StringReader *sr = new StringReader(ss.str());
	sr->Inject();
	sr->Parenthesis();

//	cout<<"============================================="<<endl;
//	cout<<"the answer is:"<<endl;
//	cout<<str + " = "<<sr->getFinalAnswer()<<endl;
//	cout<<"============================================="<<endl;
	return (str +" = "+ (sr->getFinalAnswer()));

}
string getFunction(){
	string function;
	cout<< "Please enter expression: ";
	//cin>>function;
	getline(cin,function);//this function need to link to the class stringreader.
	return dropSpace(function);
	//cout<<"Your answer is: "<<endl;
}
void help(){
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"This calculator is design to calculate simple and complex mathematics calculation."<<endl;
	cout<<"	(but please do not give a super complex expression)"<<endl;
	cout<<"	Please do not wrap entire function in parenthesis! eg. (4+(3*7)) should be 4+(3+7)"<<endl;
	cout<<"Operator specifications: "<<endl;
	cout<< "	< 'x to the power of y' == x^y >" << endl;
	cout<< "	< 'the square root of x' == sqrt:x >" << endl;
	cout<< "	< 'the nth root of x' == nrt:x, where 'n' is replaced by a number. >" << endl;
	cout<<'\t'<<"	Note: This could always just be done through x^(1/y)"<<endl;
	cout<< "	<'log base b of x' == log_b:x >" << endl;
	cout<<endl;
	cout<<"Tips: "<<endl;
	cout<<'\t'<<"* Please enter a correct and complete expression."<<endl;
	cout<<'\t'<<"* Do not enter '=' at the end of the expression."<<endl;
	cout<<'\t'<<"* Can add () in the expression."<<endl;
	cout<<'\t'<<"* Enter 'ans' to use the value from the last calculation."<<endl;
	cout<<"------------------------------------------------------------"<<endl;

}
int main(){
	string temp;
	string ans;
	char choice;
	do{
		menu();
		getline(cin,temp);
		choice= temp[0];
		switch(choice){
			case 'N':
			case 'n': 	ans=getFunction();
						break;
			case 'P':
			case 'p': 	cout<<"=============================================="<<endl;
						cout<<"previous expression and answer is: "<<endl;
						cout<<ans<<endl;
						cout<<"=============================================="<<endl;
						break;
			case 'H':
			case 'h':	help();
						break;
			case 'Q':
			case 'q':   cout<<"Thank you for using Number Calculator. Bye~ "<<endl;
						break;
			default: 	cout<<"You entered a invalid choice " << choice <<" , please try again"<<endl;
			}
		}while(choice!='Q'&& choice!='q');// one is false, all false;
	return 0;
}


/*
 update(4/4): user can enter space to the formular.
 			  program will drop the space and pass the non-space string to the
 			  string reader.


*/


