#include "NobracketString.h"
#include "Logs.h"
#include "Integers.h"


/*
update (4/8):
	1. this class will expected to receive a string of expression, (no brackets);
and seperate them into two vectors. one stores value, the other store op;
	2.it will simplify each type of the value by creating a new type object.
	3. and it will recieve a new simplfy string from the correspoinding class.
	4. and then it will do the operator, check vector op first, if it contains'*', do the * operations, and then if it only has +,-, check vector somnumbs and find the same type and do the corresponding calculation.
	5. after checking all the types throught the type vectors, and we do all we can to calculater, the answer = somenumb[0]+type[0]+somenumb[1]+type[1]+....
	5. still working on it. =)
*/
/*
update(4/9)
	1. add findOpMutiPosition(), calculating() functions to the class
example:
log_3:4 + 2/3 * 7 + 9

somenumb	op		type	index

log_3:4		+		log		0
2/3			*		frac	1
7			+		int		2
9					int		3
	2.	in this case, first we need to find * , so the findOpMutiPosition() will handle this steps, if it has "*", it will return the index position of *,
	 		if it does not have, return -1;
	3.	and then the calculating () function will assign the calculation to each operator.
			#it check the return value of the findOpMutiPosition(),
				base on the return value, if it's a -1, it will compare type vector, one by one, if it has same type, or(frac, and int), depends on the op vector, if will call the corresponding operator function.

*/
/*
 * THIS CODE only can do Logs calculation because I don't have anyother type of class I can test.
 * Integer,Pi,E,NthRoot,Fraction class if you can provide any of these class will be great.
 * I will try to work on Integer class and then I can test integer and Logs type together.
 *
 *
 */



NobracketString::NobracketString(string expression) {
	// TODO Auto-generated constructor stub
	this->expression=expression;
	cout<<"im in the NobracketString class"<<endl;
	separateString();
	simplifynumbers();
	calculating();
	formFinalAnser();
}

NobracketString::~NobracketString() {
	// TODO Auto-generated destructor stub
}

void NobracketString:: separateString(){

											//separateString and store them in the vector somenumbs
	string temp;
	for(int i=0;i<expression.length();i++){
		if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
			op.push_back(expression[i]);
			somenumbs.push_back(temp);
			temp = "";
		}
		else
			temp +=expression[i];
	}
		somenumbs.push_back(temp);
//	cout<<"before simplify: "<<endl;
//	for( vector<string>::iterator i = somenumbs.begin(); i != somenumbs.end(); ++i)
//	     cout << *i << ' ';			//check if I separate string;
//    cout<<endl;
}

void NobracketString::simplifynumbers(){ //maybe need to delete the object I create here.
for(int i = 0; i<somenumbs.size();i++){
	//cout<<"im in the simplify loop"<<endl;
	string tempnumb = somenumbs[i];
	cout<<"tempnumb is "<<tempnumb<<endl;
	if(tempnumb.find("/")<100){					//im each value, if it contains /,
//		Fraction fra = new fraction(numb1);
//		somenumbs[i]=fra->getSimplify();	//change the vector number to the 		simplify number.
			// fra->simplify();				//this = numb1
// 			replace tempnumb = fra->getAnswer();
//		if(fra->canSimplytoInt())			//if it simplifies to int
//			type.push_back("int");			// put "int" in the vector type;
//		else
			type.push_back("frac");
	}
	else if(tempnumb.find("log")<100){
		Logs* lg = new Logs(somenumbs[i]);
		somenumbs[i]=lg->getSimplify();
		if(lg->canSimplifytoInt()){			//check if it can be simplified
			type.push_back("int");
			cout<<"in the log to int here"<<endl;
											//if it simplifies to int, put "int" to vector type;
		}
		else if(lg->canSimplifytoFra()){
			type.push_back("frac");
			cout<<"in the log to fra here"<<endl;			//else if it simplifies to fraction, put "fra" to vector type;
		}else{
			type.push_back("log");
			cout<<"in the log to log here"<<endl;
		}
	}
	else if(tempnumb.find("^")<100||tempnumb.find("squrt")<100||tempnumb.find("nrt")<100){
//		NthRoot power = new NthRoot(numb1);
//												//will do the simplification in constructor.
//		somenumbs[i]=fra->getSimplify();		//get a string type
//		if(power->canSimplifytoInt()){
//			type.push_back("int");
//		}
//		else
			type.push_back("nthroot");
	}
	else if(tempnumb.find("Pi")<100){
//		Pi p = new Pi(numb1);
//		somenumbs[i]=fra->getSimplify();
//		type.push_back("pi");
	}
	else if(tempnumb.find("e")<100){
	//		E e = new E(numb1);
			type.push_back("e");
	}else{
			//Integers* integer = new Integers(somenumbs[i]);
			type.push_back("int");
		}
}

	cout<<"after simplify:"<<endl;
	for(int i = 0; i<somenumbs.size();i++){
		cout<<"somenumbs: "<<somenumbs[i]<<endl;
		cout<<" type: "<<type[i]<<endl;
	}
}

string NobracketString::getFinalAnswer(){
	return FiAnswer;
}

//int NobracketString::findOpMutiPosition(){
//	for(int i=0;i<op.size();i++){
//		if(op[i]=='*'){			//check if the op has "*",
//			return i;
//		}						// if has, return the index position
//		else
//			return -1;			//if it does not has, do nothing
//	}
//}

void NobracketString::add(string Anumb, string Atype, string Bnumb, string Btype){ 		//does not need to handle differen type here only handel same type or (fraction and integer)
	if(Atype==Btype){						//if they are the same type;
		if(Atype == "frac")
		{
					//Fraction fra = new fraction(Anumb);
					//							fra->add(Bnumb);
					//							opAnwser = fra->getAnser();
					//							isReturnOneNumb = true;
					//							//same type fraction should always return one numb
					//							//delete[] fra;				// here may need to delete the object.
		}
		else if(Atype == "int")
		{
			Integers* intnumbA = new Integers(Anumb);
			Integers* intnumbB = new Integers(Bnumb);
			intnumbA->Add(*intnumbB);
			opAnswer = intnumbA->getAnswer();
					////							//delete[] intnumb;
			isReturnOneNumb = true;
		}
		else if(Atype=="log")
		{

			Logs* lgA = new Logs(Anumb);
			Logs* lgB = new Logs(Bnumb);
			lgA->add(*lgB);
			opAnswer = lgA->getAnswer();
												//delete[] lg;
			if(opAnswer.find("+")<100)			//if the opanswer string contains "+", means it return a complex expression
				isReturnOneNumb = false;
			else
				isReturnOneNumb = true;
		}
		else if(Atype=="nthroot")
		{
					//NthRoot nthNumb = new NthRoot(numb1);
					////							nthNumb->add(Bnumb);
					////							opAnswer = nthNumb->getAnswer();
					////							if(opAnser.find("+"))			//if the opanswer string contains "+", means it return a complex expression
					////								isReturnOneNumb = false;
					////							else
					////								isReturnOneNumb = true;
		}//it is handled in the calculating()
	}else{	//if not the same type
			cout<<"add a different type value"<<endl;
		}
}

void NobracketString::substract(string Anumb,string Atype, string Bnumb, string Btype){				//does not need to handle differen type here only handel same type or (fraction and integer)
	cout<<"im in the substract()"<<endl;
	isReturnOneNumb = false;
		if(Atype==Btype){						//if they are the same type;
			if(Atype == "frac")
			{
				//Fraction fra = new fraction(Anumb);
				//							fra->add(Bnumb);
				//							opAnwser = fra->getAnser();
				//							isReturnOneNumb = true;
				//							//same type fraction should always return one numb
				//							//delete[] fra;				// here may need to delete the object.
			}
			else if(Atype == "int")
			{
				Integers* intnumbA = new Integers(Anumb);
				Integers* intnumbB = new Integers(Bnumb);
				intnumbA->Subtract(*intnumbB);
				opAnswer = intnumbA->getAnswer();
									////							//delete[] intnumb;
				isReturnOneNumb = true;
			}
			else if(Atype=="log")
			{
				Logs* lgA = new Logs(Anumb);
				Logs* lgB = new Logs(Bnumb);
				lgA->substract(*lgB);
				opAnswer = lgA->getAnswer();
											//delete[] lg;
				if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
					isReturnOneNumb = false;
				else
					isReturnOneNumb = true;
			}
			else if(Atype=="nthroot")
			{
				//NthRoot nthNumb = new NthRoot(numb1);
				////							nthNumb->add(Bnumb);
				////							opAnswer = nthNumb->getAnswer();
				////							if(opAnser.find("+"))			//if the opanswer string contains "+", means it return a complex expression
				////								isReturnOneNumb = false;
				////							else
				////								isReturnOneNumb = true;
			}//it is handled in the calculating()
		}else{	//if not the same type
			cout<<"add a different type value"<<endl;
		}
}
void NobracketString::divide(string Anumb,string Atype, string Bnumb, string Btype){			//need to handle different types calculation, basicly differen type just return as it is.
	cout<<"im in the divide()"<<endl;
	isReturnOneNumb = false;
			if(Atype==Btype){						//if they are the same type;
				if(Atype == "frac")
				{
					//Fraction fra = new fraction(Anumb);
					//							fra->add(Bnumb);
					//							opAnwser = fra->getAnser();
					//							isReturnOneNumb = true;
					//							//same type fraction should always return one numb
					//							//delete[] fra;				// here may need to delete the object.
				}
				else if(Atype == "int")
				{
					Integers* intnumbA = new Integers(Anumb);
					Integers* intnumbB = new Integers(Bnumb);
					intnumbA->Divide(*intnumbB);
					opAnswer = intnumbA->getAnswer();					//!!!!!here type has to be a "frac"!!!!!
										////							//delete[] intnumb;
					isReturnOneNumb = true;
				}
				else if(Atype=="log")
				{
					Logs* lgA = new Logs(Anumb);
					Logs* lgB = new Logs(Bnumb);
					lgA->divide(*lgB);
					opAnswer = lgA->getAnswer();
												//delete[] lg;
					if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}
				else if(Atype=="nthroot")
				{
					//NthRoot nthNumb = new NthRoot(numb1);
					////							nthNumb->add(Bnumb);
					////							opAnswer = nthNumb->getAnswer();
					////							if(opAnser.find("+"))			//if the opanswer string contains "+", means it return a complex expression
					////								isReturnOneNumb = false;
					////							else
					////								isReturnOneNumb = true;
				}//it is handled in the calculating()
			}else{	//if not the same type
				cout<<"add a different type value"<<endl;
			}
}
 void NobracketString::Multip(string Anumb,string Atype, string Bnumb, string Btype){
	 cout<<"im in the multip()"<<endl;
		isReturnOneNumb = false;
			if(Atype==Btype){						//if they are the same type;
				if(Atype == "frac")
				{
					//Fraction fra = new fraction(Anumb);
					//							fra->add(Bnumb);
					//							opAnwser = fra->getAnser();
					//							isReturnOneNumb = true;
					//							//same type fraction should always return one numb
					//							//delete[] fra;				// here may need to delete the object.
				}
				else if(Atype == "int")
				{
					Integers* intnumbA = new Integers(Anumb);
					Integers* intnumbB = new Integers(Bnumb);
					intnumbA->Multiply(*intnumbB);
					opAnswer = intnumbA->getAnswer();
										////							//delete[] intnumb;
					isReturnOneNumb = true;
				}
				else if(Atype=="log")
				{
					Logs* lgA = new Logs(Anumb);
					Logs* lgB = new Logs(Bnumb);
					lgA->Multip(*lgB);
					opAnswer = lgA->getAnswer();
												//delete[] lg;
					if(opAnswer.find("-")<100)			//if the opanswer string contains "+", means it return a complex expression
						isReturnOneNumb = false;
					else
						isReturnOneNumb = true;
				}
				else if(Atype=="nthroot")
				{
					//NthRoot nthNumb = new NthRoot(numb1);
					////							nthNumb->add(Bnumb);
					////							opAnswer = nthNumb->getAnswer();
					////							if(opAnser.find("+"))			//if the opanswer string contains "+", means it return a complex expression
					////								isReturnOneNumb = false;
					////							else
					////								isReturnOneNumb = true;
				}//it is handled in the calculating()
			}else{	//if not the same type
				cout<<"add a different type value"<<endl;
			}
}

 void NobracketString::calculating(){

 	bool havesametype=false;
 	//check for mutipositio
 	for(int i = 0;i<op.size();i++){					//check if op contains '*'
 		if(op[i]=='*'){								//if op has '*'
 			if(i==0){								// if '*' in the index position 0
 				Multip(somenumbs[0],type[0],somenumbs[1],type[1]);		//do the mulip()
 				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;
 					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
 					somenumbs.erase(somenumbs.begin()+(i+1));			//erase the second element
 					op.erase(op.begin()+(i));							//erase the '*'
 					cout<<"the mutip() get answer is now "<<somenumbs[i]<<endl;
 					cout<<"im in the calculating function delecting the '*' sign in the index 0"<<endl;
 				}
 				else{cout<<"the '*' sign in the index 0 and the answer return more then one value"<<endl;}								// if the answer return more then one value, example 5*log_3:4;
 													//keep everything as it is.
 			}
 			else{
 				Multip(somenumbs[i],type[i],somenumbs[i+1],type[i+1]);
 				if(isReturnOneNumb){									//if the answer == is return one value example: log_3:4;
 					somenumbs[i]=opAnswer;								//set the element i to the opAnser,
 					somenumbs.erase(somenumbs.begin()+(i+1));			//erase the second element
 					op.erase(op.begin()+(i));							//erase the '*'
 					cout<<"the mutip() get answer is now "<<somenumbs[i]<<endl;
 					cout<<"im in the calculating function delect '*' sign DOES NOT in the index 0"<<endl;
 				}
 				else{cout<<"the '*' sign DOES NOT in the index 0, and the answer return more then one value"<<endl;}												// if the answer return more then one value, example 5*log_3:4;
 																	//keep everything as it is.
 			}
 		}
 		else{}									//if(op[i]!='*', do nothing;
 	}											//end of checking '*'
 	for(int i=0;i<op.size();i++){				//start to check if they have the same type; ad do the calculation
 		for(int j=i+1;j<op.size()+1;j++)
 			{
 				cout<<"begin to check for type here"<<endl;
 				if(type[i]==type[j]&&op[j-1]=='*'){		//if the op is a *, skip
 					//do nothing;
 				}
 				else if(type[i]==type[j]&&op[j-1]!='*'){				//if it has same type, and op does not have *,check for operator
 					havesametype = true;
 					if(op[j-1]=='+')
 					{				//only have two case +,-
 						add(somenumbs[j],type[j],somenumbs[i],type[i]);
 						if(isReturnOneNumb)
 						{
 							somenumbs[i]=opAnswer;							//set the element i to the opAnser,
 							somenumbs.erase(somenumbs.begin()+(j));			//erase the second element
 							op.erase(op.begin()+(j-1));				//erase the op
 							cout<<"somenumb1 is now"<<somenumbs[i]<<endl;
 							cout<<"im in the calculating add(),return one value"<<endl;
 						}
 						else
 						{
 							cout<<"im in the calculating add(),return more then 1 value"<<endl; //don't change anything.
 						}
 								// here need to do something with vectors somenumb and type
 								// 3 + 7 = 10, 10 will replace 3 in somenumb vector and delete 7 and + from somenumb and type;
 								// log_3:8 + log_3:7 will return as it is, so the vectors does not change, keep as it is.
 					}
 					else					//containts "-"l
 					{
 						substract(somenumbs[j],type[j],somenumbs[i],type[i]);
 					}
 				}
 				else if((type[i]=="frac"&&type[j]=="int") || (type[j]=="frac"&&type[i]=="int"))
 				{
 										// handle one numb is fraction, one numb is integer
 					havesametype =true;
 					if(op[j-1]=='+')
 					{			//only have two case +,-
 						add(somenumbs[j],"frac",somenumbs[i],"frac");
 					}
 					else
 					{
 						substract(somenumbs[j],"frac",somenumbs[i],"frac");
 					}
 				}							//check continue comparing the next type[i+1];
 											//after loop if we cannot find the same type;
 			}//end of the int j loop
 					cout<<"end check for type here"<<endl;
 		}//end of the int i loop

// 	if(!havesametype)
// 	{										//if does not have same type, set answer as simplify version string;
// 		for(int i=0;i<op.size();i++)		//the formFinalAnser() will do this steps;
// 		{
// 			opAnswer += somenumbs[i]+op[i];
// 		}
// 		opAnswer += somenumbs[somenumbs.size()-1];
// 	}
// 	else{cout<<"it is done it's calculation"<<endl;}
 }

void NobracketString::formFinalAnser(){
	int i = 0;
	if(op.size()==0){
		FiAnswer += somenumbs[0];
	}
	else{
	for(i;i<op.size();i++){
		FiAnswer += (somenumbs[i]+op[i]);
		cout<<"im in the formfianlloop"<<endl;
	}
	FiAnswer += somenumbs[i];
	}
}
//int main(){
//
//	NobracketString* test = new NobracketString("34+log_3:4+108");
//	test->separateString();
//
//}

